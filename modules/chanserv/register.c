/*
 * Copyright (c) 2014-2018 Xtheme Development Group (Xtheme.org)
 * Copyright (c) 2005 William Pitcock, et al.
 * Rights to this code are as documented in doc/LICENSE.
 *
 * This file contains code for the CService REGISTER function.
 *
 */

#include "atheme.h"
#include "chanserv.h"

DECLARE_MODULE_V1
(
	"chanserv/register", false, _modinit, _moddeinit,
	PACKAGE_STRING,
	VENDOR_STRING
);

unsigned int ratelimit_count = 0;
time_t ratelimit_firsttime = 0;

static void cs_cmd_register(sourceinfo_t *si, int parc, char *parv[]);

command_t cs_register = { "REGISTER", N_("Registers a channel."),
                           AC_AUTHENTICATED, 3, cs_cmd_register, { .path = "cservice/register" } };

void _modinit(module_t *m)
{
        service_named_bind_command("chanserv", &cs_register);
}

void _moddeinit(module_unload_intent_t intent)
{
	service_named_unbind_command("chanserv", &cs_register);
}

static void cs_cmd_register(sourceinfo_t *si, int parc, char *parv[])
{
	channel_t *c;

	/* This command is not useful on registered channels, ignore it if
	 * it is a fantasy command so users can program bots to react on
	 * it without interference from ChanServ.
	 */
	if (si->c != NULL)
		return;

	command_fail(si, fault_needmoreparams, _("To register a channel, please use the \2Web Interface\2 at \2https://services.IRC4Fun.net/ \2"));
	return;
}
