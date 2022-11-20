#include <string>
#include <iostream>

#pragma once

class Regulator
{

public:
  virtual ~Regulator() = default;
  virtual int compute(double currentPoint, double targetPoint) = 0;
};
