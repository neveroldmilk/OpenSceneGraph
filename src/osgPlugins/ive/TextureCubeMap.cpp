/**********************************************************************
 *
 *	FILE:			TextureCubeMap.cpp
 *
 *	DESCRIPTION:	Read/Write osg::TextureCubeMap in binary format to disk.
 *
 *	CREATED BY:		Auto generated by iveGenerated
 *					and later modified by Rune Schmidt Jensen.
 *
 *	HISTORY:		Created 21.3.2003
 *
 *	Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "TextureCubeMap.h"
#include "Texture.h"
#include "Image.h"

using namespace ive;

void TextureCubeMap::write(DataOutputStream* out){
	// Write TextureCubeMap's identification.
	out->writeInt(IVETEXTURECUBEMAP);
	// If the osg class is inherited by any other class we should also write this to file.
	osg::Texture*  tex = dynamic_cast<osg::Texture*>(this);
	if(tex){
		((ive::Texture*)(tex))->write(out);
	}
	else
		throw Exception("TextureCubeMap::write(): Could not cast this osg::TextureCubeMap to an osg::Texture.");
	// Write TextureCubeMap's properties.

	// Write texture size
	int width,height;
	getTextureSize(width, height);
	out->writeInt(width);
	out->writeInt(height);

	// Write number of mipmap levels
	out->writeInt(getNumMipmapLevels());

	// Write images if any
	out->writeInt((int)getImage(osg::TextureCubeMap::POSITIVE_X));
	if(getImage(osg::TextureCubeMap::POSITIVE_X))
		((ive::Image*)(getImage(osg::TextureCubeMap::POSITIVE_X)))->write(out);

	out->writeInt((int)getImage(osg::TextureCubeMap::NEGATIVE_X));
	if(getImage(osg::TextureCubeMap::NEGATIVE_X))
		((ive::Image*)(getImage(osg::TextureCubeMap::NEGATIVE_X)))->write(out);

	out->writeInt((int)getImage(osg::TextureCubeMap::POSITIVE_Y));
	if(getImage(osg::TextureCubeMap::POSITIVE_Y))
		((ive::Image*)(getImage(osg::TextureCubeMap::POSITIVE_Y)))->write(out);

	out->writeInt((int)getImage(osg::TextureCubeMap::NEGATIVE_Y));
	if(getImage(osg::TextureCubeMap::NEGATIVE_Y))
		((ive::Image*)(getImage(osg::TextureCubeMap::NEGATIVE_Y)))->write(out);

	out->writeInt((int)getImage(osg::TextureCubeMap::POSITIVE_Z));
	if(getImage(osg::TextureCubeMap::POSITIVE_Z))
		((ive::Image*)(getImage(osg::TextureCubeMap::POSITIVE_Z)))->write(out);

	out->writeInt((int)getImage(osg::TextureCubeMap::NEGATIVE_Z));
	if(getImage(osg::TextureCubeMap::NEGATIVE_Z))
		((ive::Image*)(getImage(osg::TextureCubeMap::NEGATIVE_Z)))->write(out);

}

void TextureCubeMap::read(DataInputStream* in){
	// Peek on TextureCubeMap's identification.
	int id = in->peekInt();
	if(id == IVETEXTURECUBEMAP){
		// Read TextureCubeMap's identification.
		id = in->readInt();
		// If the osg class is inherited by any other class we should also read this from file.
		osg::Texture* tex = dynamic_cast<osg::Texture*>(this);
		if(tex){
			((ive::Texture*)(tex))->read(in);
		}
		else
			throw Exception("TextureCubeMap::read(): Could not cast this osg::TextureCubeMap to an osg::Texture.");
		// Read TextureCubeMap's properties

		// Read texture size
		int width = in->readInt();
		int height = in->readInt();
		setTextureSize(width, height);

		// Read number of mipmap levels
		setNumMipmapLevels((unsigned int)in->readInt());

		// Read images if any
		if(in->readInt()){
			osg::Image* image = new osg::Image();
			((ive::Image*)(image))->read(in);
			setImage(osg::TextureCubeMap::POSITIVE_X, image);
		}
		if(in->readInt()){
			osg::Image* image = new osg::Image();
			((ive::Image*)(image))->read(in);
			setImage(osg::TextureCubeMap::NEGATIVE_X, image);
		}
		if(in->readInt()){
			osg::Image* image = new osg::Image();
			((ive::Image*)(image))->read(in);
			setImage(osg::TextureCubeMap::POSITIVE_Y, image);
		}
		if(in->readInt()){
			osg::Image* image = new osg::Image();
			((ive::Image*)(image))->read(in);
			setImage(osg::TextureCubeMap::NEGATIVE_Y, image);
		}
		if(in->readInt()){
			osg::Image* image = new osg::Image();
			((ive::Image*)(image))->read(in);
			setImage(osg::TextureCubeMap::POSITIVE_Z, image);
		}
		if(in->readInt()){
			osg::Image* image = new osg::Image();
			((ive::Image*)(image))->read(in);
			setImage(osg::TextureCubeMap::NEGATIVE_Z, image);
		}

	}
	else{
		throw Exception("TextureCubeMap::read(): Expected TextureCubeMap identification.");
	}
}
