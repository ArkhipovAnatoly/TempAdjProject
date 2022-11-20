#pragma once
#include "Regulator.hpp"

class PIDregulator : public Regulator
{

public:
  PIDregulator() = default;
  PIDregulator(double Kp, double Ki, double Kd, double dt) : Kp(Kp), Ki(Ki), Kd(Kd), dt(dt) {}
  int compute(double currentPoint, double targetPoint) override;

  void setKp(double Kp)
  {
    this->Kp = Kp;
  }
  void setKi(double Ki)
  {
    this->Ki = Ki;
  }
  void setKd(double Kd)
  {
    this->Kd = Kd;
  }

  void setDt(double dt)
  {
    this->dt = dt;
  }
  double getKp()
  {
    return Kp;
  }
  double getKi()
  {
    return Ki;
  }
  double getKd()
  {
    return Kd;
  }

  double getDt()
  {
    return dt;
  }

private:
  double Kp = 0;
  double Ki = 0;
  double Kd = 0;
  double dt = 1;
};
