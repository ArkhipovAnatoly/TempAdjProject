#include "PIDregulator.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

static int getTemp();                                                            // Simulation getting temperature from sensor in range 10-40
static void changeTemp(double pidValue, double &temp);                           // Simulation of temperature change depending on the "signal" from the PID algorithm.
static void temperatureAdjust(PIDregulator &pid, double current, double target); // Temperature adjustment process

static void delay(uint16_t ms); // Helper function for suspending a thread

template <class T>
static void console_print(T message); // Helper function for console output

double Tcurrent = 0;

int main()
{
  const double Kp = 5.0;
  const double Ki = 0.5;
  const double Kd = 0.0;
  const double dt = 0.001;

  const double Tmin = 20.0;
  const double Tmax = 30.0;

  PIDregulator pid(Kp, Ki, Kd, dt);

  console_print("Retrieving current temperature...\n\n");
  delay(2000);
  Tcurrent = getTemp();
  console_print("Current temperature is ");
  console_print(Tcurrent);
  console_print("\n");

  if (Tcurrent < Tmin)
  {
    console_print("It's too cold. Start heating... \n\n");
    temperatureAdjust(pid, Tcurrent, Tmin);
  }

  else if (Tcurrent > Tmax)
  {
    console_print("It's too hot. Start cooling...\n\n");
    temperatureAdjust(pid, Tcurrent, Tmax);
  }
  else
  {
    console_print("Temperature is optimal:) \n\n");
  }

  return 0;
}

int getTemp()
{
  int Tmin = 10;
  int Tmax = 40;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(Tmin, Tmax);
  return dist(gen);
}

void changeTemp(double pidValue, double &temp)
{
  pidValue > 0 ? temp += 1 : temp -= 1;
}

void delay(uint16_t ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

template <class T>
static void console_print(T message)
{
  std::cout << message;
}

void temperatureAdjust(PIDregulator &pid, double current, double target)
{

  while (1)
  {

    int pidValue = pid.compute(current, target);

    if (pidValue == 0)
    {
      console_print("\nAdjustment is done!\n\n");
      return;
    }
    changeTemp(pidValue, current);

    console_print("Current temperature is ");
    console_print(current);
    console_print("\n");
    delay(500);
  }
}