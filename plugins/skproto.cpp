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
#include <QObject>
#include <QtPlugin>
#include "../src/pluginsinterfaces.h"
#include <iostream>

class SkyliveProtocol : public QObject, SkylivexPluginInterface
{
   Q_OBJECT
   Q_INTERFACES(SkylivexPluginInterface)
   //Q_PLUGIN_METADATA(IID "com.skylivex.SkylivexPlugin/1.0" FILE skproto.json)

public:
   void startPlugin();
};

void SkyliveProtocol::startPlugin()
{
   std::cout << "SkyliveProtocol initialized" << std::endl;
}

// Qt 5.0 broke compatibility with old metadata macro
//Q_EXPORT_PLUGIN2(skproto, SkyliveProtocol)