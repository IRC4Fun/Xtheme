## Xtheme

Xtheme is a set of services for IRC networks designed for large IRC networks with high
scalability requirements.  It is relatively mature software, with some code and design
derived from another package called Atheme and Shrike.

Xtheme's behavior is tunable using modules and a highly detailed configuration file.
Almost all behavior can be changed at deployment time just by editing the configuration.

If you are running this code from Git, you should read GIT-Access for instructions on
how to fully check out the Xtheme tree, as it is spread across many repositories.

**THIS VERSION OF Xtheme IRC Services IS MAINTAINED AND TAILORED FOR THE IRC4Fun IRC 
NETWORK (irc.IRC4Fun.net / https://irc4fun.net).  

THE XthemeOrg VERSION OF Xtheme IRC Services IS BEST FOR USE ON NON-IRC4Fun NETWORKS. 
[https://github.com/XthemeOrg/Xtheme](https://github.com/XthemeOrg/Xtheme)**

## Basic build instructions for the impatient

Whatever you do, make sure you do *not* install Xtheme into the same location as the source.
Xtheme will default to installing in `$HOME/xtheme`, so make sure you plan accordingly for this.

    $ git submodule update --init
    $ ./configure
    $ make
    $ make install

If you're still lost, read [INSTALL](INSTALL) or [GIT-Access](GIT-Access) for hints.
Help is also available on the [Xtheme IRC Services Wiki](https://github.com/XthemeOrg/Xtheme/wiki)

## IRC Support

THIS IRC4Fun SPECIFIC VERSION OF Xtheme IRC Services IS NOT SUPPORTED.  IT IS TAILORED 
FOR THE irc.IRC4Fun.net IRC NETWORK, WHICH UTILIZES IRC4Fun+GNUworld IRC SERVICES 
(https://irc4.fun/gnuworld) AND Nefarious2 IRCu (https://irc4.fun/nefarious)

 * [IRC](irc://irc.IRC4Fun.net/#Development) irc.IRC4Fun.net #Development
 * [IRC](irc://irc.IRC4Fun.net/#Xtheme) irc.IRC4Fun.net #Xtheme
 * [IRC](irc://chat.freenode.net/#Xtheme) chat.Freenode.net #Xtheme

## links / contact

 * [GitHub](http://www.github.com/XthemeOrg/Xtheme)
 * [Website](http://www.Xtheme.org/xtheme/)
 * [Xtheme Group Website] (http://www.Xtheme.org/)
 * [Xtheme Group News] https://xtheme.org/org-tools/newsletter
 * [IRC](irc://irc.IRC4Fun.net/#Xtheme) irc.IRC4Fun.net #Xtheme
 * [IRC](irc://chat.freenode.net/#Xtheme) chat.Freenode.net #Xtheme
