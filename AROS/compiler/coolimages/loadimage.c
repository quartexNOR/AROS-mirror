/*
    (C) 2001 AROS - The Amiga Research OS
    $Id$

    Desc:
    Lang: english
*/

#include "coolimages.h"

#define LOADIMAGE_WIDTH 23
#define LOADIMAGE_HEIGHT 16
#define LOADIMAGE_DEPTH 8

static const UBYTE loadimage_data[] =
{
	00,04,04,04,04,04,04,04,04,04,04,04,04,04,04,00,00,00,00,00,00,00,00,
	04,04,02,02,02,02,02,02,02,02,02,02,02,02,02,01,00,00,00,00,00,00,00,
	04,04,02,02,04,04,04,04,04,04,04,02,02,03,03,03,03,00,00,00,00,00,00,
	04,04,02,02,02,02,02,02,02,02,02,02,03,03,03,03,03,03,00,00,00,00,00,
	04,04,02,02,04,04,04,04,02,02,02,03,03,03,01,03,03,03,01,00,00,00,00,
	04,04,02,02,02,02,02,02,02,02,03,03,03,01,02,03,03,03,01,00,00,00,00,
	04,04,04,02,02,02,02,02,02,03,03,03,01,02,04,02,03,03,03,01,00,00,00,
	04,04,04,04,04,04,04,04,04,02,03,01,02,04,04,01,02,03,03,01,00,03,03,
	04,04,04,04,04,04,04,04,04,04,02,02,04,04,04,02,02,03,03,03,03,03,01,
	04,04,04,02,02,02,02,02,02,02,02,02,02,04,02,03,03,03,03,03,03,03,01,
	04,04,04,02,02,04,04,02,02,02,02,02,02,04,02,03,03,03,03,03,03,03,01,
	04,04,04,02,02,04,04,02,02,02,02,02,02,04,04,01,03,03,03,03,03,01,00,
	04,04,04,02,02,04,04,02,02,02,02,02,02,04,04,01,00,00,03,03,03,01,00,
	04,04,04,02,02,02,02,02,02,02,02,02,02,04,04,01,00,00,00,03,01,00,00,
	00,01,01,01,01,01,01,01,01,01,01,01,01,01,01,00,00,00,00,00,00,00,00,
	00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
};

static const UBYTE loadimage_pal[] =
{
	0xb3,0xb3,0xb3,0x00,0x00,0x00,
	0xe0,0xe0,0xe0,0x00,0x76,0x00,
	0x65,0x4b,0xbf,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff
};

const struct CoolImage cool_loadimage =
{
	loadimage_data,
	loadimage_pal,
	LOADIMAGE_WIDTH,
	LOADIMAGE_HEIGHT,
	LOADIMAGE_DEPTH
};
