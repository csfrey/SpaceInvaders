#include "raylib.h"
#include "starfield.h"

Starfield::Starfield()
{
  for (int i = 0; i < STAR_COUNT; i++)
  {
    stars[i].x = GetRandomValue(0, GetScreenWidth());
    stars[i].y = GetRandomValue(0, GetScreenHeight());
    stars[i].speed = GetRandomValue(2, 6); // Different speeds for parallax effect
    stars[i].color = (GetRandomValue(0, 100) > 50) ? WHITE : LIGHTGRAY;
  }
}

// Update: Move stars downward, reset when reaching bottom
void Starfield::Update()
{
  for (int i = 0; i < STAR_COUNT; i++)
  {
    stars[i].y += stars[i].speed;

    // If a star goes below the screen, reset it at the top
    if (stars[i].y > GetScreenHeight())
    {
      stars[i].y = 0;
      stars[i].x = GetRandomValue(0, GetScreenWidth()); // Slight variation in reset position
    }
  }
}

// Draw: Render all stars
void Starfield::Draw()
{
  for (int i = 0; i < STAR_COUNT; i++)
  {
    DrawPixelV({stars[i].x, stars[i].y}, stars[i].color);
  }
}