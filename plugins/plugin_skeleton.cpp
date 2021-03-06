/*  ____  _          _ _          __  __
 * / ___|| | ___   _| (_)_   _____\ \/ /
 * \___ \| |/ / | | | | \ \ / / _ \\  / 
 *  ___) |   <| |_| | | |\ V /  __//  \ Remote Telescopes
 * |____/|_|\_\\__, |_|_| \_/ \___/_/\_\ For the masses
 *             |___/               
 *
 * Copyright (C) 2013 Franco (nextime) Lanza <nextime@nexlab.it>
 * Copyright (C) 2013 Ivan Bellia <skylive@skylive.it>
 *
 * All rights reserved.
 *
 * This file is part of SkyliveX.
 *
 * SkyliveX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 ********************************************************************
 *
 * File: 
 * 
 * Purpose:
 *
 */
#include "pluginsinterfaces.h"
#include "ipcmsg.h"
#include <iostream>
#include "plugin_skeleton.h"
//#include "sksettings.h" // XXX Only if we need to store configs

void SkylivePluginSkeleton::startPlugin()
{
   std::cout << "SkylivePluginSkeleton initialized in thread " << thread() << std::endl;

   registerHandler((QString)"something", &SkylivePluginSkeleton::handle_getlogin);
}


void SkylivePluginSkeleton::pluginKicked()
{

}

void SkylivePluginSkeleton::receiveMessage(SKMessage msg)
{
   std::cout << "SkylivePluginSkeleton msg received: " << msg.handle.toStdString() << std::endl;
   if(_handlers.contains(msg.handle) && msg.sender != SENDER)
   {
     SKHandlerFunction mf =_handlers[msg.handle];
     (this->*mf)(msg);
   }    

}


void SkylivePluginSkeleton::sendMessage(SKMessage msg)
{
   msg.sender=SENDER;
   emit putMessage(msg);
}

void SkylivePluginSkeleton::registerHandler(QString type, SKHandlerFunction handler)
{
  _handlers[type] = handler;
   
}  

void SkylivePluginSkeleton::handle_something(SKMessage msg)
{
   std::cout << "Plugin Skeleton module handle something by " << msg.sender.toStdString() << std::endl;
    SKMessage smsg("plugin_skeleton");
    sendMessage(smsg);

    
}

