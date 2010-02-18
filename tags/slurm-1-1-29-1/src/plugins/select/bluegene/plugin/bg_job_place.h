/*****************************************************************************\
 *  bg_job_place.h - header for blue gene job placement (e.g. base partition 
 *  selection) functions. 
 *****************************************************************************
 *  Copyright (C) 2004-2006 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Dan Phung <phung4@llnl.gov> et. al.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission 
 *  to link the code of portions of this program with the OpenSSL library under 
 *  certain conditions as described in each individual source file, and 
 *  distribute linked combinations including the two. You must obey the GNU 
 *  General Public License in all respects for all of the code used other than 
 *  OpenSSL. If you modify file(s) with this exception, you may extend this 
 *  exception to your version of the file(s), but you are not obligated to do 
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in 
 *  the program, then also delete it here.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
\*****************************************************************************/

#ifndef _BG_JOB_PLACE_H_
#define _BG_JOB_PLACE_H_

#include "src/slurmctld/slurmctld.h"

/*
 * Try to find resources for a given job request
 * IN job_ptr - pointer to job record in slurmctld
 * IN/OUT bitmap - nodes availble for assignment to job, clear those not to 
 *	           be used
 * IN min_nodes, max_nodes  - minimum and maximum number of nodes to allocate 
 *	                      to this job (considers slurm partition limits)
 * IN test_only - test to see if job is ever runnable, 
 *                or (false) runable right now
 * IN test_only - if true, only test if ever could run, not necessarily now
 * IN test_only - if true, only test if ever could run, not necessarily now
 * RET - SLURM_SUCCESS if job runnable now, error code otherwise 
 */
extern int submit_job(struct job_record *job_ptr, bitstr_t *bitmap,
	       int min_nodes, int max_nodes, int req_nodes, bool test_only);

#endif /* _BG_JOB_PLACE_H_ */