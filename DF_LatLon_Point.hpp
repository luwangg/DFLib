//    DFLib: A library of Bearings Only Target Localization algorithms
//    Copyright (C) 2009-2015  Thomas V. Russo
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
// Filename       : $RCSfile$
//
// Purpose        : Implement a DFLib::Abstract::Point interface such that
//                  the "user" coordinate system is WGS84 lat/lon
//                  "XY" coordinate system is a mercator projection on the 
//                  WGS84 ellipsoid.
//
// Special Notes  : 
//
// Creator        : 
//
// Creation Date  : 
//
// Revision Information:
// ---------------------
//
// Revision Number: $Revision$
//
// Revision Date  : $Date$
//
// Current Owner  : $Author$
//-------------------------------------------------------------------------
#ifndef DF_LATLON_POINT_HPP
#define DF_LATLON_POINT_HPP

#include "DFLib_port.h"
#include <vector>
#include "proj_api.h"
#include "DF_Abstract_Point.hpp"

namespace DFLib
{
  namespace LatLon
  {
    class CPL_DLL Point : public DFLib::Abstract::Point
    {
    private:
      std::vector<double> theMerc;
      bool mercDirty;
      std::vector<double> theLatLon;
      bool llDirty;
      projPJ latlonProj, mercProj;
    public:
      /// \brief Default Constructor
      Point();

      /// \brief Constructor
      ///
      /// \param llPosition coordinates <em>in Lat Lon</em>
      Point(const std::vector<double> &llPosition);


      /// \brief Copy Constructor
      Point(const Point &right);

      /// \brief set mercator projection (XY) position
      /// 
      /// \param aPosition coordinates in mercator projection
      ///
      virtual void setXY(const std::vector<double> &aPosition);
      /// \brief get mercator projection (XY) position
      /// 
      /// \return vector of coordinates in mercator projection
      ///
      virtual const std::vector<double> &getXY();


      /// \brief get user position
      ///
      /// This is just a wrapper for getLL as needed by the abstract
      /// interface

      virtual const std::vector<double> &getUserCoords() { return getLL(); };

      /// \brief set user position
      ///
      /// This is just a wrapper for setLL as needed by the abstract
      /// interface

      virtual void setUserCoords(const std::vector<double> &uPosition)  
      { setLL(uPosition); };
	  
      /// \brief set lat/lon position
      /// 
      /// \param llPosition coordinates in Lat/Lon
      ///
      void setLL(const std::vector<double> &llPosition);
      /// \brief get Lat/Lon position
      /// 
      /// \return vector of coordinates in lat/lon
      ///
      const std::vector<double> &getLL();


      Point * Clone();
    private:
      void mercToLL();
      void llToMerc();
    };
  }
}
#endif // DF_LATLON_POINT_HPP
