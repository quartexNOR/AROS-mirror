#ifdef USE_NEWDRAWER_COLORS
const ULONG NewDrawer_colors[48] =
{
	0x00000000,0x66666666,0xffffffff,
	0xa0a0a0a0,0xa0a0a0a0,0xa0a0a0a0,
	0x44444444,0x44444444,0x44444444,
	0x66666666,0x66666666,0x66666666,
	0xdddddddd,0xbbbbbbbb,0x44444444,
	0xeeeeeeee,0xeeeeeeee,0x11111111,
	0x88888888,0x88888888,0x88888888,
	0x99999999,0x99999999,0x99999999,
	0xaaaaaaaa,0xaaaaaaaa,0xaaaaaaaa,
	0xbbbbbbbb,0xbbbbbbbb,0xbbbbbbbb,
	0xcccccccc,0xcccccccc,0xcccccccc,
	0xffffffff,0xffffffff,0xffffffff,
	0x33333333,0x33333333,0x33333333,
	0xffffffff,0xffffffff,0xffffffff,
	0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0xaaaaaaaa,
};
#endif

#define NEWDRAWER_WIDTH        33
#define NEWDRAWER_HEIGHT       29
#define NEWDRAWER_DEPTH         4
#define NEWDRAWER_COMPRESSION   0
#define NEWDRAWER_MASKING       2

#ifdef USE_NEWDRAWER_HEADER
const struct BitMapHeader NewDrawer_header =
{ 33,29,0,0,4,2,0,0,0,44,44,320,256 };
#endif

#ifdef USE_NEWDRAWER_BODY
const UBYTE NewDrawer_body[696] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x00,0x00,0x02,0xe0,
0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x03,0xfc,0x00,0x00,0x00,0x00,0x0b,0xf8,0x00,0x00,0x00,0x00,0x04,0x00,
0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xff,0x00,0x00,0x00,
0x00,0x2f,0xec,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x02,0x00,0x00,
0x00,0x00,0x00,0x00,0x3f,0xff,0xc0,0x00,0x00,0x02,0xbf,0xfa,0x80,0x00,0x00,
0x00,0x40,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,
0xf0,0x00,0x00,0x06,0xff,0xd5,0x40,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,
0x0c,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xff,0xf8,0x00,0x00,0x0c,0xff,0x6a,
0x88,0x00,0x00,0x06,0x00,0x00,0x18,0x00,0x00,0x38,0x00,0x00,0x10,0x00,0x00,
0x07,0xff,0xff,0xf0,0x00,0x00,0x04,0x3f,0xd5,0x00,0x00,0x00,0x02,0x80,0x00,
0x78,0x00,0x00,0x0c,0x80,0x00,0x70,0x00,0x00,0x03,0xff,0xff,0xf0,0x00,0x00,
0x00,0x0e,0xa8,0x40,0x00,0x00,0x02,0x20,0x01,0x98,0x00,0x00,0x04,0x20,0x01,
0x90,0x00,0x00,0x03,0xff,0xff,0xf0,0x00,0x00,0x02,0x03,0x51,0x00,0x00,0x00,
0x00,0x08,0x06,0x18,0x00,0x00,0x04,0x08,0x06,0x10,0x00,0x00,0x03,0xff,0xff,
0xf0,0x00,0x00,0x00,0x00,0x84,0x00,0x00,0x00,0x02,0x02,0x18,0x18,0x00,0x00,
0x00,0x02,0x18,0x10,0x00,0x00,0x03,0xff,0xff,0xf0,0x00,0x00,0x02,0x00,0x10,
0x00,0x00,0x00,0x00,0x00,0xe0,0x18,0x00,0x00,0x00,0x00,0xe0,0x10,0x00,0x00,
0x03,0xff,0xff,0xf0,0x00,0x00,0x02,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x40,
0x18,0x00,0x00,0x00,0x00,0x40,0x10,0x00,0x00,0x03,0xff,0xff,0xf0,0x00,0x00,
0x02,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x44,0x58,0x00,0x00,0x00,0x00,0x44,
0x50,0x00,0x00,0x03,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x44,0x80,0x00,0x00,
0x00,0x00,0xc5,0x98,0x00,0x00,0x00,0x00,0x80,0x10,0x00,0x00,0x03,0xff,0xba,
0x70,0x00,0x00,0x02,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x46,0x18,0x00,0x00,
0x00,0x00,0x44,0x18,0x00,0x00,0x03,0xff,0xfd,0xf8,0x00,0x00,0x00,0x00,0x60,
0x20,0x00,0x00,0x00,0x02,0xc0,0x7c,0x00,0x00,0x00,0x02,0x80,0x4c,0x00,0x00,
0x03,0xff,0xbf,0xc8,0x00,0x00,0x01,0x00,0x20,0x88,0x00,0x00,0x01,0x81,0x41,
0xfe,0x00,0x00,0x00,0x81,0x01,0x06,0x00,0x00,0x02,0xff,0xbf,0x00,0x00,0x00,
0x00,0xc0,0x22,0x30,0x00,0x00,0x01,0xea,0xc7,0xfc,0x00,0x00,0x01,0x2a,0x84,
0x0c,0x00,0x00,0x00,0x3f,0xbc,0x00,0x00,0x00,0x00,0x60,0x08,0xc0,0x00,0x00,
0x00,0xfd,0x5f,0xf4,0x00,0x00,0x00,0x8d,0x10,0x34,0x00,0x00,0x00,0x0f,0xb0,
0x00,0x00,0x00,0x00,0x10,0x23,0x00,0x00,0x00,0x00,0x7e,0xff,0xd0,0x00,0x00,
0x00,0x62,0x80,0xd0,0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,0x04,0x0c,
0x00,0x00,0x00,0x00,0x1f,0xff,0x40,0x00,0x00,0x00,0x18,0x83,0x40,0x00,0x00,
0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x01,0x30,0x00,0x00,0x00,0x00,0x07,0xfd,
0x00,0x00,0x00,0x00,0x06,0x0d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xf4,0x00,0x00,0x00,0x00,0x01,0xf4,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xa0,0x00,0x00,0x00,0x00,0x00,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00, };
#endif