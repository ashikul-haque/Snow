/* -*- c++ -*- */
/*
 * Copyright 2022 ESL.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SNOW_DEMOD_IMPL_H
#define INCLUDED_SNOW_DEMOD_IMPL_H

#include <snow/demod.h>
#include <fstream>

namespace gr {
namespace snow {

class demod_impl : public demod
{
private:
    // input variables from xml
      bool d_enable_log;
      float d_threshold;
      int d_fft_size;
      std::vector<int> d_subcarriers;

      //variable to analyze data
      long long sample_count;
      //std::vector<long> multiply_factor;
      long multiply_factor[64];
      int flags[3];
      int counts[3];
      int count0[3];
      int count1[3];

      std::ofstream log_file;
      std::ofstream data_file[64];

public:
    demod_impl(bool enable_log,
               float threshold,
               int fft_size,
               std::vector<int> subcarriers);
    ~demod_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace snow
} // namespace gr

#endif /* INCLUDED_SNOW_DEMOD_IMPL_H */
