// Datastructures.hh

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <unordered_map>
#include <algorithm>
#include <math.h>

// Types for IDs
using StopID = long int;
using RegionID = std::string;
using Name = std::string;

// Return values for cases where required thing was not found
StopID const NO_STOP = -1;
RegionID const NO_REGION = "!!NO_REGION!!";

// Return value for cases where integer values were not found
int const NO_VALUE = std::numeric_limits<int>::min();

// Return value for cases where name values were not found
Name const NO_NAME = "!!NO_NAME!!";

// Type for a coordinate (x, y)
struct Coord
{
    int x = NO_VALUE;
    int y = NO_VALUE;
};

// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};

// Type for a stop
struct Stop;
struct Region;

struct Stop{
    StopID stopid = NO_STOP;
    Name stop_name = NO_NAME;
    Coord stop_coord = NO_COORD;
    Region* region_stop_belongs = nullptr;  // a stop can only have one region to belong to
};

// Type for a stop
struct Region{
    RegionID region_id = NO_REGION;
    Name region_name = NO_NAME;
    std::vector<Stop*> stops_region_contain; // a region can have many stops.
    Region* parent_region = nullptr; // a region can only have one parent region
    std::vector<Region*> sub_regions; // a region can have multiple subregions
};

// Example: Defining == and hash function for Coord so that it can be used
// as key for std::unordered_map/set, if needed
inline bool operator==(Coord c1, Coord c2) { return c1.x == c2.x && c1.y == c2.y; }
inline bool operator!=(Coord c1, Coord c2) { return !(c1==c2); } // Not strictly necessary

// Defining < for Coord so that it can be used
// first compare normal euclidean distance, and then compare y if euclidean distance of both are same
inline bool operator<(Coord c1, Coord c2)
{
    double c1_xy = sqrt(c1.x * c1.x + c1.y * c1.y);
    double c2_xy = sqrt(c2.x * c2.x + c2.y * c2.y);
    if (c1_xy < c2_xy) { return true; }
    else if (c2_xy < c1_xy) { return false; }
    else { return c1.y < c2.y; }
}

inline bool operator>(Coord c1, Coord c2)
{
    if (! (c1<c2) && c1 != c2){
        return true;
    }else{
        return false;
    }
}

// This is the class you are supposed to implement

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance: constant
    // Short rationale for estimate: performance of function .size() is constant
    int stop_count();

    // Estimate of performance: linear O(n)
    // Short rationale for estimate: performance of function .clear() is linear
    void clear_all();

    // Estimate of performance: linear O(stops_.size)
    // Short rationale for estimate: traverse the unordered_map(stops_)
    std::vector<StopID> all_stops();

    // Estimate of performance: Constant on average, worst case: O(stops_.size)
    // Short rationale for estimate: use unordered_map.insert() function
    bool add_stop(StopID id, Name const& name, Coord xy);

    // Estimate of performance: Constant on average, worst case O(stops_.size)
    // Short rationale for estimate: use unordered_map.find() function
    Name get_stop_name(StopID id);

    // Estimate of performance: Constant on average, worst case O(stops_.size)
    // Short rationale for estimate: use unordered_map.find() function
    Coord get_stop_coord(StopID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: linearithmic(stops_.size)
    // Short rationale for estimate:first copy id and name of all the elements in stops_ into vector (linear)
    // Then sort this vector according to name (linearithmic)
    std::vector<StopID> stops_alphabetically();

    // Estimate of performance: linearithmic(stops_.size)
    // Short rationale for estimate: first copy id and coordinator of all the elements in stops_ into vector (linear)
    // Then sort this vector according to coordinator (linearithmic)
    std::vector<StopID> stops_coord_order();

    // Estimate of performance: O(stops_.size)
    // Short rationale for estimate: use function min_element
    StopID min_coord();

    // Estimate of performance: O(stops_.size)
    // Short rationale for estimate: use function max_element
    StopID max_coord();

    // Estimate of performance: linear
    // Short rationale for estimate: need to traverse the unodered_map
    std::vector<StopID> find_stops(Name const& name);

    // Estimate of performance: constant on average and linear at worst
    // Short rationale for estimate: only use .find function
    bool change_stop_name(StopID id, Name const& newname);

    // Estimate of performance: constant on average and linear at worst
    // Short rationale for estimate: only use .find function
    bool change_stop_coord(StopID id, Coord newcoord);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: Constant on average, worst case: O(regions_.size)
    // Short rationale for estimate: use unordered_map.insert() function
    bool add_region(RegionID id, Name const& name);

    // Estimate of performance: Constant on average, worst case: O(regions_.size)
    // Short rationale for estimate: only use .find() function
    Name get_region_name(RegionID id);

    // Estimate of performance: linear, O(regions_.size)
    // Short rationale for estimate: need to traverse the unordered_map(regions_)
    std::vector<RegionID> all_regions();

    // Estimate of performance: constant on average, worst case O(stops_.size + regions_.size)
    // Short rationale for estimate: find the id and parentid,
    // and add id to region.stops and add parentid to stops.parent_region
    bool add_stop_to_region(StopID id, RegionID parentid);

    // Estimate of performance: constant on average, worst case O(2*regions_.size)
    // Short rationale for estimate: find id and parentid
    // and add id to regions(parentid).subregions and add parentid to regions(id).parent_region
    bool add_subregion_to_region(RegionID id, RegionID parentid);

    // Estimate of performance: O(regions.size)
    // Short rationale for estimate: find id and add stops(id).parent_region to vector
    // then add parent_region.parent_region to vector, then the number added at most is regions.size
    std::vector<RegionID> stop_regions(StopID id);

    // Non-compulsory operations

    // Estimate of performance:
    // Short rationale for estimate:
    void creation_finished();

    // Estimate of performance: O(stop.size)
    // Short rationale for estimate: find the stops that a region and its subregions contains(travers the stops at most)
    // Then find the bounding_box for this vector
    std::pair<Coord, Coord> region_bounding_box(RegionID id);

    // Estimate of performance: O(stops.size)
    // Short rationale for estimate: traverse the unordered_map and then
    // compare distance value when adding element
    std::vector<StopID> stops_closest_to(StopID id);

    // Estimate of performance: O(stops_.size)
    // Short rationale for estimate: through id, find the region the stop belongs to
    // and then remove this stop in region.substops, and this is a vector,
    // performance of .erase() function is linear, then remove this stop from stops_
    bool remove_stop(StopID id);

    // Estimate of performance: O(regions.size)
    // Short rationale for estimate: first find the regions1 of id1 and regions2 of id2
    // using above function (stop_regions), and the performance of this function is linear
    // then find the common string in these two vectors in a reverse order. And performance of
    // this method is O(regions.size)
    RegionID stops_common_region(StopID id1, StopID id2);

private:
    // Add stuff needed for your class implementation here
    std::unordered_map<StopID, Stop> stops_;

    std::unordered_map<RegionID, Region> regions_;

    // given a vector of stop pointer, find the bounding box of these stops
    std::pair<Coord,Coord> bounding_box_of_stops(std::vector<Stop*> stops_vector);

    // compare a cood with coord_bounding and update the bounding box if this coord is outside the bounding box
    void update_bounding_box(std::pair<Coord, Coord>& coord_bouding, Coord coord);

    std::vector<Stop*> region_stops(Region region, std::vector<Stop*> stops);

    // find the distance between stop1 and stop2
    double euclidean_distance(Stop stop1, Stop stop2);


};

#endif // DATASTRUCTURES_HH
