/**********************************************************************
 *
 *	FILE:			MatrixTransform.cpp
 *
 *	DESCRIPTION:	Read/Write osg::MatrixTransform in binary format to disk.
 *
 *	CREATED BY:		Auto generated by iveGenerated
 *					and later modified by Rune Schmidt Jensen.
 *
 *	HISTORY:		Created 17.3.2003
 *
 *	Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "MatrixTransform.h"
#include "Group.h"

using namespace ive;

void MatrixTransform::write(DataOutputStream* out){
	// Write MatrixTransform's identification.
	out->writeInt(IVEMATRIXTRANSFORM);

	// If the osg class is inherited by any other class we should also write this to file.
	osg::Group*  group = dynamic_cast<osg::Group*>(this);
	if(group){
		((ive::Group*)(group))->write(out);
	}
	else
		throw Exception("MatrixTransform::write(): Could not cast this osg::MatrixTransform to an osg::Group.");


	// Write MatrixTransform's properties.
	out->writeMatrix(getMatrix());
}

void MatrixTransform::read(DataInputStream* in){
	// Read MatrixTransform's identification.
	int id = in->peekInt();
	if(id == IVEMATRIXTRANSFORM){
		// Code to read MatrixTransform's properties.
		id = in->readInt();
		// If the osg class is inherited by any other class we should also read this from file.
		osg::Group*  group = dynamic_cast<osg::Group*>(this);
		if(group){
			((ive::Group*)(group))->read(in);
		}
		else
			throw Exception("MatrixTransform::read(): Could not cast this osg::MatrixTransform to an osg::Group.");

		// Read matrix
		setMatrix(in->readMatrix());
	}
	else{
		throw Exception("MatrixTransform::read(): Expected MatrixTransform identification");
	}
}
