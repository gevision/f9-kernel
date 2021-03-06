/* Copyright (c) 2013 The F9 Microkernel Project. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/* Debug options */
#define CONFIG_DEBUG
#define CONFIG_KDB

/* Enable KProbes, dynamic instrumentation system */
#define CONFIG_KPROBES

/* Generate symbol map */
#define CONFIG_SYMMAP

/* Table sizes */
enum {
	CONFIG_MAX_THREADS	= 32,
	CONFIG_MAX_KT_EVENTS	= 64,
	CONFIG_MAX_ASYNC_EVENTS	= 32,
	CONFIG_MAX_ADRESS_SPACES = 16,
	CONFIG_MAX_FPAGES = 256
};

#define CONFIG_KTIMER_HEARTBEAT		65536
#define CONFIG_KTIMER_MINTICKS		128

#define CONFIG_LARGEST_FPAGE_SHIFT	16
#define CONFIG_SMALLEST_FPAGE_SHIFT	8
#define CONFIG_SMALLEST_FPAGE_SIZE		(1 << CONFIG_SMALLEST_FPAGE_SHIFT)

#define CONFIG_INTR_THREAD_MAX	256

#define CONFIG_KIP_EXTRA_SIZE	128

#define CONFIG_BITMAP_BITBAND

#define CONFIG_PANIC_DUMP_STACK

/* resolve depenedency of the above configurations */
#if defined(CONFIG_SYMMAP) && !defined(CONFIG_KPROBES)
/* sampling/symmap depends on KProbes */
#undef CONFIG_SYMMAP
#endif

#endif /* CONFIG_H_ */
