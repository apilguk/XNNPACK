// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <emmintrin.h>

#include <xnnpack/common.h>
#include <xnnpack/math.h>
#include <xnnpack/transpose.h>

void xnn_x16_transpose_ukernel__8x8_sse2(
    const uint16_t* input,
    uint16_t* output,
    size_t input_stride,
    size_t output_stride,
    size_t block_width,
    size_t block_height)
{
  assert(output_stride >= block_height * sizeof(uint16_t));
  assert(input_stride >= block_width * sizeof(uint16_t));

  const size_t tile_height = 8;
  const size_t tile_width = 8;
  const size_t tile_hbytes = tile_height * sizeof(uint16_t);
  const size_t tile_wbytes = tile_width * sizeof(uint16_t);
  const size_t input_reset = tile_wbytes - round_down_po2(block_height, 8) * input_stride;
  const size_t output_reset = tile_width * output_stride - round_down_po2(block_height, 2) * sizeof(uint16_t);

  const uint16_t* i0 = input;
  uint16_t* o0 = (uint16_t*) output;

  do {
    size_t bh = block_height;
    for (; bh >= 8; bh -= 8) {
      __m128i v0 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);
      __m128i v1 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);
      __m128i v2 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);
      __m128i v3 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);
      __m128i v4 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);
      __m128i v5 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);
      __m128i v6 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);
      __m128i v7 = _mm_loadu_si128((const __m128i*) i0);
      i0 = (uint16_t*) ((uintptr_t) i0 + input_stride);

      __m128i vtmp0 = _mm_unpacklo_epi16(v0, v1);
      __m128i vtmp1 = _mm_unpacklo_epi16(v2, v3);
      __m128i vtmp2 = _mm_unpacklo_epi16(v4, v5);
      __m128i vtmp3 = _mm_unpacklo_epi16(v6, v7);
      __m128i vtmp4 = _mm_unpackhi_epi16(v0, v1);
      __m128i vtmp5 = _mm_unpackhi_epi16(v2, v3);
      __m128i vtmp6 = _mm_unpackhi_epi16(v4, v5);
      __m128i vtmp7 = _mm_unpackhi_epi16(v6, v7);

      v0 = _mm_unpacklo_epi32(vtmp0, vtmp1);
      v1 = _mm_unpacklo_epi32(vtmp2, vtmp3);
      v2 = _mm_unpackhi_epi32(vtmp0, vtmp1);
      v3 = _mm_unpackhi_epi32(vtmp2, vtmp3);
      v4 = _mm_unpacklo_epi32(vtmp4, vtmp5);
      v5 = _mm_unpacklo_epi32(vtmp6, vtmp7);
      v6 = _mm_unpackhi_epi32(vtmp4, vtmp5);
      v7 = _mm_unpackhi_epi32(vtmp6, vtmp7);

      vtmp0 = _mm_unpacklo_epi64(v0, v1);
      vtmp1 = _mm_unpackhi_epi64(v0, v1);
      vtmp2 = _mm_unpacklo_epi64(v2, v3);
      vtmp3 = _mm_unpackhi_epi64(v2, v3);
      vtmp4 = _mm_unpacklo_epi64(v4, v5);
      vtmp5 = _mm_unpackhi_epi64(v4, v5);
      vtmp6 = _mm_unpacklo_epi64(v6, v7);
      vtmp7 = _mm_unpackhi_epi64(v6, v7);

      size_t rem = min(block_width - 1, 7);
      uint16_t* o1 = (uint16_t*) ((uintptr_t) o0 + rem * output_stride);
      switch(rem){
        case (7):
          _mm_storeu_si128((__m128i*) o1, vtmp7);
          o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
        case (6):
          _mm_storeu_si128((__m128i*) o1, vtmp6);
          o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
        case (5):
          _mm_storeu_si128((__m128i*) o1, vtmp5);
          o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
        case (4):
          _mm_storeu_si128((__m128i*) o1, vtmp4);
          o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
        case (3):
          _mm_storeu_si128((__m128i*) o1, vtmp3);
          o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
        case (2):
          _mm_storeu_si128((__m128i*) o1, vtmp2);
          o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
        case (1):
          _mm_storeu_si128((__m128i*) o1, vtmp1);
      }
      _mm_storeu_si128((__m128i*) o0, vtmp0);
      o0 = (uint16_t*) ((uintptr_t) o0 + tile_hbytes);
    }

    if (bh != 0) {
      __m128i v0 = _mm_loadu_si128((const __m128i*) i0);
      const uint16_t* i1 = (const uint16_t*) ((uintptr_t) i0 + input_stride);
      if XNN_UNPREDICTABLE(bh < 2) {
        i1 = i0;
      }
      __m128i v1 = _mm_loadu_si128((const __m128i*) i1);
      i1 = (uint16_t*) ((uintptr_t) i1 + input_stride);
      if XNN_UNPREDICTABLE(bh <= 2) {
        i1 = i0;
      }
      __m128i v2 = _mm_loadu_si128((const __m128i*) i1);
      i1 = (uint16_t*) ((uintptr_t) i1 + input_stride);
      if XNN_UNPREDICTABLE(bh < 4) {
        i1 = i0;
      }
      __m128i v3 = _mm_loadu_si128((const __m128i*) i1);
      i1 = (uint16_t*) ((uintptr_t) i1 + input_stride);
      if XNN_UNPREDICTABLE(bh <= 4) {
        i1 = i0;
      }
      __m128i v4 = _mm_loadu_si128((const __m128i*) i1);
      i1 = (uint16_t*) ((uintptr_t) i1 + input_stride);
      if XNN_UNPREDICTABLE(bh < 6) {
        i1 = i0;
      }
      __m128i v5 = _mm_loadu_si128((const __m128i*) i1);
      i1 = (uint16_t*) ((uintptr_t) i1 + input_stride);
      if XNN_UNPREDICTABLE(bh <= 6) {
        i1 = i0;
      }
      __m128i v6 = _mm_loadu_si128((const __m128i*) i1);

      __m128i vtmp0 = _mm_unpacklo_epi16(v0, v1);
      __m128i vtmp1 = _mm_unpacklo_epi16(v2, v3);
      __m128i vtmp2 = _mm_unpacklo_epi16(v4, v5);
      __m128i vtmp3 = _mm_unpacklo_epi16(v6, v6);
      __m128i vtmp4 = _mm_unpackhi_epi16(v0, v1);
      __m128i vtmp5 = _mm_unpackhi_epi16(v2, v3);
      __m128i vtmp6 = _mm_unpackhi_epi16(v4, v5);
      __m128i vtmp7 = _mm_unpackhi_epi16(v6, v6);

      v0 = _mm_unpacklo_epi32(vtmp0, vtmp1);
      v1 = _mm_unpacklo_epi32(vtmp2, vtmp3);
      v2 = _mm_unpackhi_epi32(vtmp0, vtmp1);
      v3 = _mm_unpackhi_epi32(vtmp2, vtmp3);
      v4 = _mm_unpacklo_epi32(vtmp4, vtmp5);
      v5 = _mm_unpacklo_epi32(vtmp6, vtmp7);
      v6 = _mm_unpackhi_epi32(vtmp4, vtmp5);
      __m128i v7 = _mm_unpackhi_epi32(vtmp6, vtmp7);

      vtmp0 = _mm_unpacklo_epi64(v0, v1);
      vtmp1 = _mm_unpackhi_epi64(v0, v1);
      vtmp2 = _mm_unpacklo_epi64(v2, v3);
      vtmp3 = _mm_unpackhi_epi64(v2, v3);
      vtmp4 = _mm_unpacklo_epi64(v4, v5);
      vtmp5 = _mm_unpackhi_epi64(v4, v5);
      vtmp6 = _mm_unpacklo_epi64(v6, v7);
      vtmp7 = _mm_unpackhi_epi64(v6, v7);

      size_t rem = min(block_width - 1, 7);
      if (bh & 4) {
        uint16_t* o1 = (uint16_t*) ((uintptr_t) o0 + rem * output_stride);
        switch(rem){
          case (7):
            _mm_storel_epi64((__m128i*) o1, vtmp7);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (6):
            _mm_storel_epi64((__m128i*) o1, vtmp6);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (5):
            _mm_storel_epi64((__m128i*) o1, vtmp5);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (4):
            _mm_storel_epi64((__m128i*) o1, vtmp4);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (3):
            _mm_storel_epi64((__m128i*) o1, vtmp3);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (2):
            _mm_storel_epi64((__m128i*) o1, vtmp2);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (1):
            _mm_storel_epi64((__m128i*) o1, vtmp1);
        }
        _mm_storel_epi64((__m128i*) o0, vtmp0);
        o0 += 4;
        vtmp0 = _mm_unpackhi_epi64(vtmp0, vtmp0);
        vtmp1 = _mm_unpackhi_epi64(vtmp1, vtmp1);
        vtmp2 = _mm_unpackhi_epi64(vtmp2, vtmp2);
        vtmp3 = _mm_unpackhi_epi64(vtmp3, vtmp3);
        vtmp4 = _mm_unpackhi_epi64(vtmp4, vtmp4);
        vtmp5 = _mm_unpackhi_epi64(vtmp5, vtmp5);
        vtmp6 = _mm_unpackhi_epi64(vtmp6, vtmp6);
        vtmp7 = _mm_unpackhi_epi64(vtmp7, vtmp7);
      }

      if (bh & 2) {
        uint16_t* o1 = (uint16_t*) ((uintptr_t) o0 + rem * output_stride);
        switch(rem){
          case (7):
            *((int*) o1) = _mm_cvtsi128_si32(vtmp7);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (6):
            *((int*) o1) = _mm_cvtsi128_si32(vtmp6);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (5):
            *((int*) o1) = _mm_cvtsi128_si32(vtmp5);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (4):
            *((int*) o1) = _mm_cvtsi128_si32(vtmp4);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (3):
            *((int*) o1) = _mm_cvtsi128_si32(vtmp3);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (2):
            *((int*) o1) = _mm_cvtsi128_si32(vtmp2);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (1):
            *((int*) o1) = _mm_cvtsi128_si32(vtmp1);
        }
        *((int*) o0) = _mm_cvtsi128_si32(vtmp0);
        o0 += 2;
        vtmp0 = _mm_srli_epi64(vtmp0, 32);
        vtmp1 = _mm_srli_epi64(vtmp1, 32);
        vtmp2 = _mm_srli_epi64(vtmp2, 32);
        vtmp3 = _mm_srli_epi64(vtmp3, 32);
        vtmp4 = _mm_srli_epi64(vtmp4, 32);
        vtmp5 = _mm_srli_epi64(vtmp5, 32);
        vtmp6 = _mm_srli_epi64(vtmp6, 32);
        vtmp7 = _mm_srli_epi64(vtmp7, 32);
      }
      if (bh & 1) {
        uint16_t* o1 = (uint16_t*) ((uintptr_t) o0 + rem * output_stride);
        switch(rem){
          case (7):
            *o1 = (uint16_t) _mm_cvtsi128_si32(vtmp7);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (6):
            *o1 = (uint16_t) _mm_cvtsi128_si32(vtmp6);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (5):
            *o1 = (uint16_t) _mm_cvtsi128_si32(vtmp5);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (4):
            *o1 = (uint16_t) _mm_cvtsi128_si32(vtmp4);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (3):
            *o1 = (uint16_t) _mm_cvtsi128_si32(vtmp3);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (2):
            *o1 = (uint16_t) _mm_cvtsi128_si32(vtmp2);
            o1 = (uint16_t*) ((uintptr_t) o1 - output_stride);
          case (1):
            *o1 = (uint16_t) _mm_cvtsi128_si32(vtmp1);
        }
        *o0 = (uint16_t) _mm_cvtsi128_si32(vtmp0);
      }
    }
    i0 = (uint16_t*) ((uintptr_t) i0 + input_reset);
    o0 = (uint16_t*) ((uintptr_t) o0 + output_reset);
    block_width = doz(block_width, tile_width);
  } while (block_width != 0);
}
