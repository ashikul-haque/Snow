/* -*- c++ -*- */
/*
 * Copyright 2022 ESL.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SNOW_DEMOD_H
#define INCLUDED_SNOW_DEMOD_H

#include <gnuradio/sync_block.h>
#include <snow/api.h>

namespace gr {
namespace snow {

/*!
 * \brief <+description of block+>
 * \ingroup snow
 *
 */
class SNOW_API demod : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<demod> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of snow::demod.
     *
     * To avoid accidental use of raw pointers, snow::demod's
     * constructor is in a private implementation
     * class. snow::demod::make is the public interface for
     * creating new instances.
     */
    static sptr
    make(bool enable_log, float threshold, int fft_size, std::vector<int> subcarriers);
};

} // namespace snow
} // namespace gr

#endif /* INCLUDED_SNOW_DEMOD_H */
