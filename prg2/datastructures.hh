
// Datastructures.hh

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>



// Types for IDs
using StopID = long int;
using RegionID = std::string;
using RouteID = std::string;
using Name = std::string;


// Return values for cases where required thing was not found
RouteID const NO_ROUTE = "!!NO_ROUTE!!";
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

// Example: Defining == and hash function for Coord so that it can be used
// as key for std::unordered_map/set, if needed
inline bool operator==(Coord c1, Coord c2) { return c1.x == c2.x && c1.y == c2.y; }
inline bool operator!=(Coord c1, Coord c2) { return !(c1==c2); } // Not strictly necessary

// Example: Defining < for Coord so that it can be used
// as key for std::map/set
inline bool operator<(Coord c1, Coord c2)
{
    if (c1.y < c2.y) { return true; }
    else if (c2.y < c1.y) { return false; }
    else { return c1.x < c2.x; }
}

// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};

// Type for time of day in minutes from midnight (i.e., 60*hours + minutes)
using Time = int;

// Return value for cases where color was not found
Time const NO_TIME = std::numeric_limits<Time>::min();

// Type for a duration of time (in minutes)
using Duration = int;

// Return value for cases where Duration is unknown
Duration const NO_DURATION = NO_VALUE;

// Type for a distance (in metres)
using Distance = int;

// Return value for cases where Duration is unknown
Distance const NO_DISTANCE = NO_VALUE;

struct Stop;
struct JourneyEdge;
struct TripEdge;

// Type for a stop
struct Stop{
    Name stop_name = NO_NAME;
    Coord stop_coord = NO_COORD;
    std::vector<JourneyEdge> edges;
};

// Type for a edge to store distance information
struct JourneyEdge{
    StopID to_stop = NO_STOP;
    RouteID route_id = NO_ROUTE;
    Distance distance = NO_DISTANCE;
};

// Type for Edge to store time information

struct TripEdge{
    StopID to_stop = NO_STOP;
    Time time_from = NO_TIME;
    Time time_to = NO_TIME;
};

// Types for the info used in trip printing
using TripTuple = std::tuple<StopID, RouteID, Time>;


// Types for the info used in journey printing
using StopTuple = std::tuple<StopID, RouteID, Distance>;


// define my priority queue used in operations, journey_shortest_distance and journey_earliest_arrival
// To calculate the priority according to the third value(distance or time) of the last element in the vector.
using Tuple = std::tuple<StopID, RouteID, int>;
struct my_comparator
{
    // queue elements are vectors so we need to compare those
    bool operator()(std::vector<Tuple> const& vec1, std::vector<Tuple> const& vec2) const
    {

        // compare the distance of last tuple
        return std::get<2>(vec1.back()) > std::get<2>(vec2.back());
    }
};

// define the priority queue
using my_priority_queue = std::priority_queue<std::vector<Tuple>, std::vector<std::vector<Tuple>>, my_comparator>;

// This is the class you are supposed to implement

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance:
    // Short rationale for estimate:
    int stop_count();

    // Estimate of performance:
    // Short rationale for estimate:
    void clear_all();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<StopID> all_stops();

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_stop(StopID id, Name const& name, Coord xy);

    // Estimate of performance:
    // Short rationale for estimate:
    Name get_stop_name(StopID id);

    // Estimate of performance:
    // Short rationale for estimate:
    Coord get_stop_coord(StopID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<StopID> stops_alphabetically();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<StopID> stops_coord_order();

    // Estimate of performance:
    // Short rationale for estimate:
    StopID min_coord();

    // Estimate of performance:
    // Short rationale for estimate:
    StopID max_coord();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<StopID> find_stops(Name const& name);

    // Estimate of performance:
    // Short rationale for estimate:
    bool change_stop_name(StopID id, Name const& newname);

    // Estimate of performance:
    // Short rationale for estimate:
    bool change_stop_coord(StopID id, Coord newcoord);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_region(RegionID id, Name const& name);

    // Estimate of performance:
    // Short rationale for estimate:
    Name get_region_name(RegionID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<RegionID> all_regions();

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_stop_to_region(StopID id, RegionID parentid);

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_subregion_to_region(RegionID id, RegionID parentid);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<RegionID> stop_regions(StopID id);

    // Non-compulsory operations

    // Estimate of performance:
    // Short rationale for estimate:
    void creation_finished();

    // Estimate of performance:
    // Short rationale for estimate:
    std::pair<Coord, Coord> region_bounding_box(RegionID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<StopID> stops_closest_to(StopID id);

    // Estimate of performance:
    // Short rationale for estimate:
    bool remove_stop(StopID id);

    // Estimate of performance:
    // Short rationale for estimate:
    RegionID stops_common_region(StopID id1, StopID id2);

    // Phase 2 operations

    // Estimate of performance: O(allRoutes_.size())
    // Short rationale for estimate: need to iterate through all elements in allRoutes_
    std::vector<RouteID> all_routes();

    // Estimate of performance: O(allRoutes.size+allStops.size)
    // Short rationale for estimate: find routeid also find stopids in allStops
    bool add_route(RouteID id, std::vector<StopID> stops);

    // Estimate of performance: O(allRoutes.size+allStops.size)
    // Short rationale for estimate: first find the stopid and iterate through all routes passing through this stop
    std::vector<std::pair<RouteID, StopID>> routes_from(StopID stopid);

    // Estimate of performance: O(allRoutes.size)
    // Short rationale for estimate: only need to find the routeid and then return the value of this id
    std::vector<StopID> route_stops(RouteID id);

    // Estimate of performance:O(allStops.size + allRoutes.size + allTrips.size)
    // Short rationale for estimate: clear all the routes and trips
    void clear_routes();

    // Estimate of performance: O(allStops.size+allStops.values.size)
    // Short rationale for estimate: implement the DFS algorithm and all edges are stored in allStops.values
    std::vector<std::tuple<StopID, RouteID, Distance>> journey_any(StopID fromstop, StopID tostop);

//     Non-compulsory operations

    // Estimate of performance: O(allStops.size+allStops.values.size)
    // Short rationale for estimate: implement the BFS algorithm
    std::vector<std::tuple<StopID, RouteID, Distance>> journey_least_stops(StopID fromstop, StopID tostop);

    // Estimate of performance: O(allStops.size+allStops.values.size)
    // Short rationale for estimate: implement the DFS algorithm
    std::vector<std::tuple<StopID, RouteID, Distance>> journey_with_cycle(StopID fromstop);

    // Estimate of performance: O((allStops.size + allStops.values.size)*lg(allStops.size))
    // Short rationale for estimate: implement Dijkstra algorithm
    std::vector<std::tuple<StopID, RouteID, Distance>> journey_shortest_distance(StopID fromstop, StopID tostop);

    // Estimate of performance: O(allRoutes.size+allStops.size)
    // Short rationale for estimate: first find the routeid, and then store time information in stops
    // so we need to iterate all stops if this route passing through all the stops in the worst case.
    bool add_trip(RouteID routeid, const std::vector<Time> &stop_times);

    // Estimate of performance: O(allRoutes.size+allTrips.size)
    // Short rationale for estimate: find the routeid in allTrips
    // then iterate through allRoutes if all the routes passing  through this stop in the worst case.
    std::vector<std::pair<Time, Duration> > route_times_from(RouteID routeid, StopID stopid);

    // Estimate of performance: O((allStops.size + allStops.values.size + allTrips.values.values.size)*lg(allStops.size))
    // Short rationale for estimate: This is also the Dijkstra algorithm, but different from journey_shortest_distance,
    // It need more operations to iterate through all the time pairs to find proper time. And in data structure allTrips,
    // allTrips.values.values(allTrips.second.second) consists of all time pairs.
    std::vector<std::tuple<StopID, RouteID, Time>> journey_earliest_arrival(StopID fromstop, StopID tostop, Time starttime);

    // Estimate of performance:
    // Short rationale for estimate:
    void add_walking_connections(); // Note! This method is completely optional, and not part of any testing

private:

    std::unordered_map<StopID, Stop> allStops_;
    std::unordered_map<RouteID, std::vector<StopID>> allRoutes_;
    std::unordered_map<StopID, std::unordered_map<RouteID, std::vector<TripEdge>>> allTrips_;

    // find the euclidean distance between stop1 and stop2
    // the value is rounded down to the nearest integer
    int distance(Stop stop1, Stop stop2);


};

#endif // DATASTRUCTURES_HH
