#include <seqan3/alignment/configuration/align_config_band.hpp>
#include <seqan3/alignment/configuration/align_config_gap.hpp>
#include <seqan3/alignment/scoring/gap_scheme.hpp>
#include <seqan3/core/algorithm/configuration.hpp>
#include <seqan3/core/algorithm/pipeable_config_element.hpp>
#include <seqan3/core/debug_stream.hpp>

int main()
{
    using seqan3::get;

    seqan3::configuration my_cfg = seqan3::align_cfg::gap{seqan3::gap_scheme{seqan3::gap_score{-1},
                                                                             seqan3::gap_open_score{-10}}} |
                                   seqan3::align_cfg::band_fixed_size{seqan3::align_cfg::lower_diagonal{-4},
                                                                      seqan3::align_cfg::upper_diagonal{4}};
    // my_cfg is now of type configuration<gap, band>

    seqan3::debug_stream << get<1>(my_cfg).lower_diagonal                                  << '\n';  // prints -4
    seqan3::debug_stream << get<seqan3::align_cfg::band_fixed_size>(my_cfg).upper_diagonal << '\n';  // prints 4
    seqan3::debug_stream << get<seqan3::align_cfg::gap>(my_cfg).value.get_gap_score()      << '\n';  // prints -1
}
