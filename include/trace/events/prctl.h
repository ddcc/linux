/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM prctl

#if !defined(_TRACE_EVENTS_PRCTL_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_EVENTS_PRCTL_H

#include <linux/tracepoint.h>

TRACE_EVENT(prctl,
	TP_PROTO(int option, unsigned long arg2, unsigned long arg3,
		     unsigned long arg4, unsigned long arg5, long *error),

	TP_ARGS(option, arg2, arg3, arg4, arg5, error),

	TP_STRUCT__entry(
	    __field(int, option)
	    __field(unsigned long, arg2)
	    __field(unsigned long, arg3)
	    __field(unsigned long, arg4)
	    __field(unsigned long, arg5)
	    __field(long, ret)
	),

	TP_fast_assign(
	    __entry->option	= option;
	    __entry->arg2	= arg2;
	    __entry->arg3	= arg3;
	    __entry->arg4	= arg4;
	    __entry->arg5	= arg5;
	    __entry->ret	= *error;
	),

	TP_printk("opt=%u arg2=0x%lx arg3=0x%lx arg4=0x%lx arg5=0x%lx, ret=%ld",
		__entry->option, __entry->arg2, __entry->arg3, __entry->arg4,
		__entry->arg5, __entry->ret)
);

#endif /* _TRACE_EVENTS_PRCTL_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
