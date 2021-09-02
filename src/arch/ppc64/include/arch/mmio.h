/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __ARCH_MMIO_H__
#define __ARCH_MMIO_H__

#include <stdint.h>

/* NOTE: In some cases accesses to MMIO must be separated by eieio intruction
 * to prevent reordering. This is not included in functions below (performance
 * reasons) and must be called explicitly. Function eieio() is defined in io.h.
 */

static inline uint8_t read8(const volatile void *addr)
{
	uint8_t val;
	asm volatile(
		"lbzcix %0, 0, %1":
		"=r"(val) : "r"(addr));

	return val;
}

static inline uint16_t read16(const volatile void *addr)
{
	uint16_t val;
	asm volatile(
		"lhzcix %0, 0, %1":
		"=r"(val) : "r"(addr));

	return val;
}

static inline uint32_t read32(const volatile void *addr)
{
	uint32_t val;
	asm volatile(
		"lwzcix %0, 0, %1":
		"=r"(val) : "r"(addr));

	return val;
}

static inline uint64_t read64(const volatile void *addr)
{
	uint64_t val;
	asm volatile(
		"ldcix %0, 0, %1":
		"=r"(val) : "r"(addr));

	return val;
}

static inline void write8(volatile void *addr, uint8_t val)
{
	asm volatile(
		"stbcix %0, 0, %1"::
		"r"(val), "r"(addr));
}

static inline void write16(volatile void *addr, uint16_t val)
{
	asm volatile(
		"sthcix %0, 0, %1"::
		"r"(val), "r"(addr));
}

static inline void write32(volatile void *addr, uint32_t val)
{
	asm volatile(
		"stwcix %0, 0, %1"::
		"r"(val), "r"(addr));
}

static inline void write64(volatile void *addr, uint64_t val)
{
	asm volatile(
		"stdcix %0, 0, %1"::
		"r"(val), "r"(addr));
}

#endif /* __ARCH_MMIO_H__ */
