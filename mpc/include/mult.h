#pragma once

#include <gmp.h>

#include "NetworkNode.h"

void mult(std::map<std::set<int>, mpz_t>* c, std::map<std::set<int>, mpz_t>* a, std::map<std::set<int>, mpz_t>* b, uint size, uint ring_size);
void multPub();
void preBeaver();
void beavers_mult();