#ifndef CLUSTERING_H
#define CLUSTERING_H

/*

This file is part of VROOM.

Copyright (c) 2015-2017, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <algorithm>
#include <unordered_set>
#include <vector>

#include "../../../structures/vroom/amount.h"
#include "../../../structures/vroom/input/input.h"
#include "../../../structures/vroom/job.h"

// Clustering types.
enum class CLUSTERING_T { PARALLEL, SEQUENTIAL };

class clustering {
private:
  const input& input_ref;
  void parallel_clustering();
  void sequential_clustering();

public:
  const CLUSTERING_T type;
  const double regret_coeff;
  std::vector<std::vector<index_t>> clusters;
  // Cost of all edges added during the clustering process
  cost_t edges_cost;
  std::unordered_set<job_t> unassigned;

  clustering(const input& input, CLUSTERING_T t, double c);
};


#endif
