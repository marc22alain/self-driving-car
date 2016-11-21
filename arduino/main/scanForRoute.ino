// STATE: scanning with range-finder for a clear route
void scanForRoute() {
  int degrees = 0;
  // ...either turn
  // argument is target heading
  turn(degrees);

  // ...or
  driveBackwards();
}
