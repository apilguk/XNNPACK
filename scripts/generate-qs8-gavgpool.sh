#!/bin/sh
# Copyright 2020 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

################################### Scalar ####################################
tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=1 -D REQUANTIZATION=FP32 -D VARIANT=IMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-imagic-c1.c &
tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=2 -D REQUANTIZATION=FP32 -D VARIANT=IMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-imagic-c2.c &
tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=4 -D REQUANTIZATION=FP32 -D VARIANT=IMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-imagic-c4.c &

tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=1 -D REQUANTIZATION=FP32 -D VARIANT=FMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-fmagic-c1.c &
tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=2 -D REQUANTIZATION=FP32 -D VARIANT=FMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-fmagic-c2.c &
tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=4 -D REQUANTIZATION=FP32 -D VARIANT=FMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-fmagic-c4.c &

tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=1 -D REQUANTIZATION=FP32 -D VARIANT=LRINTF -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-lrintf-c1.c &
tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=2 -D REQUANTIZATION=FP32 -D VARIANT=LRINTF -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-lrintf-c2.c &
tools/xngen src/qs8-gavgpool/unipass-scalar.c.in -D ROW_TILE=7 -D CHANNEL_TILE=4 -D REQUANTIZATION=FP32 -D VARIANT=LRINTF -D WASM=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-scalar-lrintf-c4.c &

tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=1 -D REQUANTIZATION=FP32 -D VARIANT=IMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-imagic-c1.c &
tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=2 -D REQUANTIZATION=FP32 -D VARIANT=IMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-imagic-c2.c &
tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=4 -D REQUANTIZATION=FP32 -D VARIANT=IMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-imagic-c4.c &

tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=1 -D REQUANTIZATION=FP32 -D VARIANT=FMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-fmagic-c1.c &
tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=2 -D REQUANTIZATION=FP32 -D VARIANT=FMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-fmagic-c2.c &
tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=4 -D REQUANTIZATION=FP32 -D VARIANT=FMAGIC -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-fmagic-c4.c &

tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=1 -D REQUANTIZATION=FP32 -D VARIANT=LRINTF -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-lrintf-c1.c &
tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=2 -D REQUANTIZATION=FP32 -D VARIANT=LRINTF -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-lrintf-c2.c &
tools/xngen src/qs8-gavgpool/multipass-scalar.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=4 -D REQUANTIZATION=FP32 -D VARIANT=LRINTF -D WASM=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-scalar-lrintf-c4.c &

################################## ARM NEON ###################################
tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=8  -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neon-c8.c &
tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=16 -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neon-c16.c &
tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=24 -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neon-c24.c &
tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=32 -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neon-c32.c &

tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=8  -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neonv8-c8.c &
tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=16 -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neonv8-c16.c &
tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=24 -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neonv8-c24.c &
tools/xngen src/qs8-gavgpool/unipass-neon.c.in -D ROW_TILE=7 -D CHANNEL_TILE=32 -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7x-minmax-fp32-neonv8-c32.c &

tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=8  -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neon-c8.c &
tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=16 -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neon-c16.c &
tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=24 -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neon-c24.c &
tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=32 -D REQUANTIZATION=FP32 -D ARMV8=0 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neon-c32.c &

tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=8  -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neonv8-c8.c &
tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=16 -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neonv8-c16.c &
tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=24 -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neonv8-c24.c &
tools/xngen src/qs8-gavgpool/multipass-neon.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=32 -D REQUANTIZATION=FP32 -D ARMV8=1 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-neonv8-c32.c &

################################## WAsm SIMD ##################################
tools/xngen src/qs8-gavgpool/unipass-wasmsimd.c.in -D ROW_TILE=7 -D CHANNEL_TILE=8  -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-wasmsimd-c8.c &
tools/xngen src/qs8-gavgpool/unipass-wasmsimd.c.in -D ROW_TILE=7 -D CHANNEL_TILE=16 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-wasmsimd-c16.c &
tools/xngen src/qs8-gavgpool/unipass-wasmsimd.c.in -D ROW_TILE=7 -D CHANNEL_TILE=24 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-wasmsimd-c24.c &
tools/xngen src/qs8-gavgpool/unipass-wasmsimd.c.in -D ROW_TILE=7 -D CHANNEL_TILE=32 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-wasmsimd-c32.c &

tools/xngen src/qs8-gavgpool/multipass-wasmsimd.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=8  -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-wasmsimd-c8.c &
tools/xngen src/qs8-gavgpool/multipass-wasmsimd.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=16 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-wasmsimd-c16.c &
tools/xngen src/qs8-gavgpool/multipass-wasmsimd.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=24 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-wasmsimd-c24.c &
tools/xngen src/qs8-gavgpool/multipass-wasmsimd.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=32 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-wasmsimd-c32.c &

################################### x86 SSE ###################################
tools/xngen src/qs8-gavgpool/unipass-sse.c.in -D ROW_TILE=7 -D CHANNEL_TILE=8  -D SSE=2 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-sse2-c8.c &
tools/xngen src/qs8-gavgpool/unipass-sse.c.in -D ROW_TILE=7 -D CHANNEL_TILE=16 -D SSE=2 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-sse2-c16.c &
tools/xngen src/qs8-gavgpool/unipass-sse.c.in -D ROW_TILE=7 -D CHANNEL_TILE=24 -D SSE=2 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-sse2-c24.c &

tools/xngen src/qs8-gavgpool/unipass-sse.c.in -D ROW_TILE=7 -D CHANNEL_TILE=8  -D SSE=4 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-sse41-c8.c &
tools/xngen src/qs8-gavgpool/unipass-sse.c.in -D ROW_TILE=7 -D CHANNEL_TILE=16 -D SSE=4 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-sse41-c16.c &
tools/xngen src/qs8-gavgpool/unipass-sse.c.in -D ROW_TILE=7 -D CHANNEL_TILE=24 -D SSE=4 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7x-minmax-fp32-sse41-c24.c &

tools/xngen src/qs8-gavgpool/multipass-sse.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=8  -D SSE=2 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-sse2-c8.c &
tools/xngen src/qs8-gavgpool/multipass-sse.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=16 -D SSE=2 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-sse2-c16.c &
tools/xngen src/qs8-gavgpool/multipass-sse.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=24 -D SSE=2 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-sse2-c24.c &

tools/xngen src/qs8-gavgpool/multipass-sse.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=8  -D SSE=4 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-sse41-c8.c &
tools/xngen src/qs8-gavgpool/multipass-sse.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=16 -D SSE=4 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-sse41-c16.c &
tools/xngen src/qs8-gavgpool/multipass-sse.c.in -D ROW_TILE=7 -D ROW_SUBTILE=7 -D CHANNEL_TILE=24 -D SSE=4 -D REQUANTIZATION=FP32 -o src/qs8-gavgpool/gen/7p7x-minmax-fp32-sse41-c24.c &

################################## Unit tests #################################
tools/generate-gavgpool-test.py --spec test/qs8-gavgpool-minmax-fp32.yaml --output test/qs8-gavgpool-minmax-fp32.cc &

wait
