// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <xnnpack/common.h>
#include <xnnpack/params.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_X64_TRANSPOSE_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(const uint64_t* input,      \
                            uint64_t* output,           \
                            size_t input_stride,        \
                            size_t output_stride,       \
                            size_t block_width,         \
                            size_t block_height);

DECLARE_X64_TRANSPOSE_UKERNEL_FUNCTION(xnn_x64_transpose_ukernel__2x2_sse2);

#define DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(const uint32_t* input,      \
                            uint32_t* output,           \
                            size_t input_stride,        \
                            size_t output_stride,       \
                            size_t block_width,         \
                            size_t block_height);

DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(xnn_x32_transpose_ukernel__4x4_aarch64_neon_tbl);
DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(xnn_x32_transpose_ukernel__4x4_sse);
DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(xnn_x32_transpose_ukernel__4x4_sse2);
DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(xnn_x32_transpose_ukernel__4x4_wasmsimd);

#define DECLARE_X16_TRANSPOSE_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(const uint16_t* input,      \
                            uint16_t* output,           \
                            size_t input_stride,        \
                            size_t output_stride,       \
                            size_t block_width,         \
                            size_t block_height);

DECLARE_X16_TRANSPOSE_UKERNEL_FUNCTION(xnn_x16_transpose_ukernel__4x8_sse2);
DECLARE_X16_TRANSPOSE_UKERNEL_FUNCTION(xnn_x16_transpose_ukernel__8x8_sse2);

#define DECLARE_X8_TRANSPOSE_UKERNEL_FUNCTION(fn_name)  \
  XNN_INTERNAL void fn_name(const uint8_t* input,       \
                            uint8_t* output,            \
                            size_t input_stride,        \
                            size_t output_stride,       \
                            size_t block_width,         \
                            size_t block_height);

DECLARE_X8_TRANSPOSE_UKERNEL_FUNCTION(xnn_x8_transpose_ukernel__16x16_sse2);

#ifdef __cplusplus
}  // extern "C"
#endif
