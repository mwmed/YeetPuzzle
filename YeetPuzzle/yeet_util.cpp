#include "yeet_util.h"
#include <random>
std::random_device dev;
int yeet::rand_int(int min, int max)
{
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
    return dist6(rng);
}
