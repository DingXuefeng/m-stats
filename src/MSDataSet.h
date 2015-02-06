/*
 * Class collecting MSDataPoints belonging to a single data set.
 */

#ifndef MST_MSDataSet_H
#define MST_MSDataSet_H

#include "MSDataObject.h"
#include "MSDataPoint.h"

// c++ libs
#include <string>
#include <iostream>
#include <stdlib.h>

namespace mst {

class MSDataPoint;

class MSDataSet : public MSDataObject
{
   public:
      //! Constructor
      MSDataSet(const std::string& name = "");
      //! Destructor
      ~MSDataSet();

      //! Add new point (the function takes ownership of the object)
      void AddDataPoint(MSDataPoint* dataPoint) {
         if (fVector) fVector->push_back(dataPoint);
      }
      //! Get pointer to a point
      MSDataPoint* GetDataPoint(unsigned int index) const {
         if (index < fVector->size()) return fVector->at(index);
         else {
            std::cerr << "MSDataSet::GetDataPoint: index our of range\n";
            exit(1);
         }
      }

      //! Get observable value for a specific data point
      double GetDataPoint(int index, const std::string& field) const {
         return fVector ? fVector->at(index)->Get(field) : 0;
      }

      //! Get number of data points
      unsigned int  GetNDataPoints() const {
         return fVector ? fVector->size() : 0;
      }

      //! Clear data set
      void Clear() { if (fVector) fVector->clear(); }

      //! Print data set content
      void Print() const;

   private:
      //! Pointer to the vector of data points
      MSDataPointVector* fVector;
};

} // namespace mst

#endif // MST_MSDataSet_H
