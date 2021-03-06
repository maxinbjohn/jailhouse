/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Copyright (c) Siemens AG, 2014, 2015
 *
 * Authors:
 *  Jan Kiszka <jan.kiszka@siemens.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#include <asm/cell.h>
#include <asm/psci.h>
#include <asm/smp.h>

static struct smp_ops tegra124_smp_ops = {
	.type = SMP_SPIN,
	.init = psci_cell_init,
	.cpu_spin = psci_emulate_spin,
};

void register_smp_ops(struct cell *cell)
{
	cell->arch.smp = &tegra124_smp_ops;
}
