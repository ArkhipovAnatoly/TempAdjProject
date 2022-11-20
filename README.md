# Description

The program uses the "PID Algorithm" to adjust the temperature between 20 and 30. The "Current Temperature" is obtained from a random number generator that generates numbers **between 10 and 40**. If the "Current Temperature" is **less than 20**, the "PID Algorithm" runs " heat". until the temperature is **20**, otherwise, if the "Current temperature" is **greater than 30**, the "PID algorithm" starts "cooling" until the temperature is **30**. If the "Current temperature" is in **range 20-30**, "PID-algorithm" does nothing.

The **_"sample_lib"_** directory contains the sources for the "PID Algorithm".

The **_"sample_program"_** directory contains an example of using the "PID Algorithm".
