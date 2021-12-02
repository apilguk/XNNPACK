// Auto-generated file. Do not edit!
//   Template: src/f32-qs8-vcvt/scalar-magic.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/common.h>
#include <xnnpack/math.h>
#include <xnnpack/vcvt.h>

#include <fp16.h>


void xnn_f32_qs8_vcvt_ukernel__scalar_magic_x1(
    size_t n,
    const float* x,
    int8_t* y,
    const union xnn_f32_qs8_cvt_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(n != 0);
  assert(x != NULL);
  assert(y != NULL);

  const float vscale = params->scalar_magic.scale;
  const float vmagic_bias = params->scalar_magic.magic_bias;
  const int32_t vmagic_min = params->scalar_magic.magic_min;
  const int32_t vmagic_max = params->scalar_magic.magic_max;
  const int32_t vmagic_bias_less_zero_point = params->scalar_magic.magic_bias_less_zero_point;

  do {
    float vx = *x++;
    vx *= vscale;
    vx += vmagic_bias;

    int32_t vy = (int32_t) fp32_to_bits(vx);
    vy = math_max_s32(vy, vmagic_min);
    vy = math_min_s32(vy, vmagic_max);
    vy -= vmagic_bias_less_zero_point;

    *y++ = (int8_t) vy;

    n -= sizeof(int8_t);
  } while (n != 0);
}