#ifndef STARFIELD_H
#define STARFIELD_H

#include "star.h"

const int STAR_COUNT = 100; // Total number of stars

class Starfield
{
public:
  Starfield();
  void Update();
  void Draw();

private:
  Star stars[STAR_COUNT];
};

#endif