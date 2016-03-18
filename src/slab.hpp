// slab.hpp
// Aaron G. Tumulak

#pragma once

// std includes
#include <iostream>
#include <vector>
#include <set>

// sn-solver includes
#include "cell.hpp"
#include "layout.hpp"
#include "settings.hpp"

class Slab
{
    public:

        // Default constructor
        Slab( const Settings &settings, const Layout &layout );

        // Solve for k eigenvalue
        void EigenvalueSolve();

        // Solve for fixed source
        void FixedSourceSolve();

        // Print scalar fluxes
        void PrintScalarFluxes();

        // Print angular fluxes
        void PrintAngularFluxes();

        // Friend functions //
 
        // Overload operator<<()
        friend std::ostream &operator<< ( std::ostream &out, const Slab &obj );

    private:

        // Sweep right
        void SweepRight();

        // Sweep left
        void SweepLeft();

        // Check if k eigenvalue is converged. If not, create new fission source.
        bool KConverged();

        // Check if scalar flux is converged
        bool ScalarFluxConverged( unsigned int i );

        // Calculate new cell scatter sources
        void UpdateScatterSources();

        // Calculate new cell fission sources
        void UpdateFissionSources();

        // Const Settings
        const Settings settings_;

        // Const Layout
        const Layout layout_;

        // Current k eigenvalue
        double cur_k_;

        // Previous k eigenvalue
        double prev_k_;

        // Current fission source
        double cur_fission_source_;

        // Previous fission source
        double prev_fission_source_;

        // Vector of cells
        std::vector<Cell> cells_;

        // Set of energy groups for problem
        std::set<double> energy_groups_;
};

// Friend functions //

// Overload operator<<()
std::ostream &operator<< ( std::ostream &out, const Slab &obj );
