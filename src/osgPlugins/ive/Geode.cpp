/**********************************************************************
 *
 *	FILE:			Geode.cpp
 *
 *	DESCRIPTION:	Read/Write osg::Geode in binary format to disk.
 *
 *	CREATED BY:		Auto generated by iveGenerated
 *					and later modified by Rune Schmidt Jensen.
 *
 *	HISTORY:		Created 18.3.2003
 *
 *	Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "Node.h"
#include "Geode.h"
#include "Geometry.h"

#include <osg/Node>
#include <osg/Geometry>

using namespace ive;

void Geode::write(DataOutputStream* out){
	// Write Geode's identification.
	out->writeInt(IVEGEODE);
	// If the osg class is inherited by any other class we should also write this to file.
	osg::Node*  node = dynamic_cast<osg::Node*>(this);
	if(node){
		((ive::Node*)(node))->write(out);
	}
	else
		throw Exception("Geode::write(): Could not cast this osg::Geode to an osg::Node.");


	// Write Geode's properties.

	// Write number of drawables.
	out->writeInt(getNumDrawables());
	// Write out every drawable.
    for(unsigned int i=0;i<getNumDrawables();i++){
		osg::Drawable* drawable = getDrawable(i);
		if(dynamic_cast<osg::Geometry*>(drawable))
			((ive::Geometry*)(drawable))->write(out);
		else{
			throw Exception("Unknown drawable in Geode::write()");
		}
    }
}

void Geode::read(DataInputStream* in){
	// Read Geode's identification.
	int id = in->peekInt();
	if(id == IVEGEODE){
		// Code to read Geode's properties.
		id = in->readInt();
		// If the osg class is inherited by any other class we should also read this from file.
		osg::Node*  node = dynamic_cast<osg::Node*>(this);
		if(node){
			((ive::Node*)(node))->read(in);
		}
		else
			throw Exception("Geode::read(): Could not cast this osg::Geode to an osg::Node.");


		// Read number of drawables.
		int size = in->readInt();
		// Read the drawables.
		for(int i = 0; i<size; i++){
			int id = in->peekInt();
			osg::Drawable* drawable;
			if(id == IVEGEOMETRY){
				drawable = new osg::Geometry();				
				((Geometry*)(drawable))->read(in);
				addDrawable(drawable);
			}
			else
				throw Exception("Unknown drawable identification in Geode::read()");
		
		}
	}
	else{
		throw Exception("Geode::read(): Expected Geode identification.");
	}
}
