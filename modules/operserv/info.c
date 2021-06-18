/*
 * Copyright (c) 2014-2018 Xtheme Development Group <www.Xtheme.org>
 * Copyright (c) 2010 Atheme Development Group, et al.
 * Copyright (c) 2016-2017 ChatLounge IRC Network Development Team
 *
 * Rights to this code are as documented in doc/LICENSE.
 *
 * This file contains code for OS INFO
 *
 */

#include "atheme.h"

DECLARE_MODULE_V1
(
	"operserv/info", false, _modinit, _moddeinit,
	PACKAGE_STRING,
	VENDOR_STRING
);

static void os_cmd_info(sourceinfo_t *si, int parc, char *parv[]);

command_t os_info = { "INFO", N_("Shows some useful information about the current settings of services."), PRIV_SERVER_AUSPEX, 1, os_cmd_info, { .path = "oservice/info" } };

void _modinit(module_t *m)
{
        service_named_bind_command("operserv", &os_info);
}

void _moddeinit(module_unload_intent_t intent)
{
	service_named_unbind_command("operserv", &os_info);
}

static void os_cmd_info(sourceinfo_t *si, int parc, char *parv[])
{
	mowgli_node_t *tn, *n2;

	logcommand(si, CMDLOG_GET, "INFO");

	command_success_nodata(si, _("\2General Uworld2 Information---\2"));
	command_success_nodata(si, "%s [%s] Build Date: %s", PACKAGE_STRING, revision, __DATE__);
	command_success_nodata(si, _("Uworld2 has been up for\2 %s \2- PID: %d"), timediff(CURRTIME - me.start), getpid());
	command_success_nodata(si, _("\2General Configuration---\2"));
	command_success_nodata(si, _("How often changes are written to the database: %d minutes"), config_options.commit_interval / 60);
	command_success_nodata(si, _("Default GLINE time: %d days"), config_options.akill_time / 86400);
	MOWGLI_ITER_FOREACH(n2, config_options.exempts.head)
	{
		command_success_nodata(si, _("user@host mask(s) that are auto G-line exempt: %s"), (char *)n2->data);
	}
	command_success_nodata(si, _("Default maximum number of clones allowed: %d"), config_options.default_clone_allowed);
	command_success_nodata(si, _("Will services be sending WALLOPS/GLOBOPS about various things: %s"), config_options.silent ? "no" : "yes");
	command_success_nodata(si, _("Show entity IDs to everyone: %s"),
		config_options.show_entity_id ? "Yes" : "No");
	command_success_nodata(si, _("\2Flood Protection Configuration---\2"));
	command_success_nodata(si, _("How many messages before a flood is triggered, (if 0, flood protection is disabled): %d"), config_options.flood_msgs);
	command_success_nodata(si, _("How long before the flood counter resets: %d seconds"), config_options.flood_time);
	command_success_nodata(si, _("Number of commands used before ratelimiting starts, (if 0, ratelimiting is disabled): %d"), config_options.ratelimit_uses);
	command_success_nodata(si, _("How long before ratelimiting counter resets, (if 0, ratelimiting is disabled): %d seconds"), config_options.ratelimit_period);
	command_success_nodata(si, _("\2Other Configuration & Contrib Modules---\2"));

	if (IS_TAINTED)
	{
		mowgli_node_t *n;

		command_success_nodata(si, _("Services is presently \2TAINTED\2, no support will be given for this configuration."));
		command_success_nodata(si, _("List of active taints:"));

		MOWGLI_ITER_FOREACH(n, taint_list.head)
		{
			taint_reason_t *tr = n->data;

			command_success_nodata(si, _("Taint Condition: %s"), tr->condition);
			command_success_nodata(si, _("Taint Location: %s:%d"), tr->file, tr->line);
			command_success_nodata(si, _("Taint Explanation: %s"), tr->buf);
		}
	}

	hook_call_operserv_info(si);
}

/* vim:cinoptions=>s,e0,n0,f0,{0,}0,^0,=s,ps,t0,c3,+s,(2s,us,)20,*30,gs,hs
 * vim:ts=8
 * vim:sw=8
 * vim:noexpandtab
 */
