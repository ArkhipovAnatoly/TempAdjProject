#include "PIDregulator.hpp"

int PIDregulator::compute(double currentPoint, double targetPoint)
{
  static double integral = 0, prevErr = 0;
  double err = targetPoint - currentPoint;
  integral += err * dt;
  double D = (err - prevErr) / dt;
  prevErr = err;
  return (err * Kp + integral * Ki + D * Kd);
}