#ifndef LOCATION_2D_H
#define LOCATION_2D_H

typedef struct Location {
	short x;
	short y;
} Location;

enum RelativeLocation {
	NORTH,
	NORTHEAST,
	EAST,
	SOUTHEAST,
	SOUTH,
	SOUTHWEST,
	WEST,
	NORTHWEST
};

#endif