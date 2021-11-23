// Datastructures.cc

#include "datastructures.hh"

#include <random>
#include <cmath>
#include <stdexcept>

std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{

}

Datastructures::~Datastructures()
{
}

int Datastructures::stop_count()
{
    return stops_.size(); // constant
}

void Datastructures::clear_all()
{
    stops_.clear(); // Linear in the size of the container
    regions_.clear(); // Linear in the size of the container
}

std::vector<StopID> Datastructures::all_stops()
{
    std::vector<StopID> all_stops;
    if (! stops_.empty()){  // constant

        for (auto& p: stops_){ // Linear
            all_stops.push_back(p.first); // performance of push_back() in a vector is constant
        }
    }
    return all_stops;
}

bool Datastructures::add_stop(StopID id, const Name& name, Coord xy)
{
    Stop stop = {id,name,xy};
    // Constant on average, worst case linear in the size of the container.
    bool if_insert = stops_.insert({id, stop}).second;
    return if_insert;
}

Name Datastructures::get_stop_name(StopID id) // often called
{
    // Constant on average, worst case linear in the size of the container.
    auto iter = stops_.find(id);
    if (iter != stops_.end()) {
        return iter->second.stop_name;
    } else {
        return NO_NAME;
    }
}

Coord Datastructures::get_stop_coord(StopID id) // often called
{
    // Constant on average, worst case linear in the size of the container.
    auto iter = stops_.find(id);
    if (iter != stops_.end()) {
        return iter->second.stop_coord;
    }else {
        return NO_COORD;
    }
}

std::vector<StopID> Datastructures::stops_alphabetically() // performance is linearithmic
{
    std::vector<StopID> stops_alphabetically;

    std::vector<std::pair<StopID, Name>> stops_tmp;

    if (! stops_.empty()){   //constant

        // first, copy elements(only StopID and name) in unordered_map stops_ to the vector stops_tmp
        // because sorting vector is faster than sorting map
        // the performance of copying is linear
        for (auto& p: stops_){ // Linear
            stops_tmp.push_back({p.first, p.second.stop_name}); // performance of push_back() in a vector is constant
        }

        // Then sort the vector stops_tmp according to stop_name
        // performance: linearithmic
        std::sort(stops_tmp.begin(), stops_tmp.end(),
            [](std::pair<StopID, Name>& stop1, std::pair<StopID, Name>& stop2) { return stop1.second < stop2.second;});

        // finally copy element.first(StopID) to stops_alphabetically
        // performance is linear
        for (std::pair<StopID, Name> stop : stops_tmp){
            stops_alphabetically.push_back(stop.first);
        }
    }
    return stops_alphabetically;;
}

std::vector<StopID> Datastructures::stops_coord_order()  // performance is linearithmic
{
    std::vector<StopID> stops_coord_order;

    std::vector<std::pair<StopID, Coord>> stops_tmp;

    if (! stops_.empty()){   //constant

        // first, copy elements(only StopID and coord) in unordered_map stops_ to the vector stops_tmp
        // because sorting vector is faster than sorting map
        // the performance of copying is linear
        for (auto& p: stops_){ // Linear
            stops_tmp.push_back({p.first, p.second.stop_coord}); // performance of push_back() in a vector is constant
        }

        // Then sort the vector stops_tmp according to stop_coord
        // performance: linearithmic
        std::sort(stops_tmp.begin(), stops_tmp.end(),
            [](std::pair<StopID, Coord>& stop1, std::pair<StopID, Coord>& stop2) { return stop1.second < stop2.second;});

        // finally copy element.first(StopID) to stops_alphabetically
        // performance is linear
        for (std::pair<StopID, Coord> stop : stops_tmp){
            stops_coord_order.push_back(stop.first);
        }

    }
    return stops_coord_order;


}

StopID Datastructures::min_coord() // O(stops_.size)
{
    if (!stops_.empty()){   //constant
        std::unordered_map<StopID, Stop>::iterator stopid_with_min_coord;
        stopid_with_min_coord = std::min_element(stops_.begin(), stops_.end(),
            [](std::pair<StopID, Stop> stop1, std::pair<StopID, Stop> stop2){
                return stop1.second.stop_coord < stop2.second.stop_coord;
        });

        return stopid_with_min_coord->first;
    }

    return NO_STOP;
}

StopID Datastructures::max_coord() // O(stops_.size)
{
    if (! stops_.empty()){   //constant
        std::unordered_map<StopID, Stop>::iterator stopid_with_max_coord;
        stopid_with_max_coord = std::max_element(stops_.begin(), stops_.end(),
            [](std::pair<StopID, Stop> stop1, std::pair<StopID, Stop> stop2){
                return stop1.second.stop_coord < stop2.second.stop_coord;
        });

        return stopid_with_max_coord->first;

    }
    return NO_STOP;

}

std::vector<StopID> Datastructures::find_stops(Name const& name) // not often, performance: linear
{
    std::vector<StopID> stops_by_name;

    for (auto& p: stops_){ // Linear

        if (p.second.stop_name == name){
            stops_by_name.push_back(p.first); // performance of push_back() in a vector is constant
        }
    }

    return stops_by_name;
}

bool Datastructures::change_stop_name(StopID id, const Name& newname) // constant
{    
    auto search = stops_.find(id);
    if(search != stops_.end()) {  // constant
        stops_[id].stop_name = newname;
        return true;

    } else {
        return false;
    }

}

bool Datastructures::change_stop_coord(StopID id, Coord newcoord) // constant
{
    auto search = stops_.find(id);
    if(search != stops_.end()) {           // constant
        stops_[id].stop_coord = newcoord;
        return true;

    } else {
        return false;
    }
}

bool Datastructures::add_region(RegionID id, const Name &name) // constant on average
{
    Region region;
    region.region_id = id;
    region.region_name = name;

    // Constant on average, worst case linear in the size of the container.
    bool if_insert = regions_.insert({id,region}).second;
    return if_insert;
}

Name Datastructures::get_region_name(RegionID id) // called ofter and performance is constant on average
{
    // Constant on average, worst case linear in the size of the container.
    auto iter = regions_.find(id);
    if (iter != regions_.end()) {
        return iter->second.region_name;
    } else {
        return NO_NAME;
    }
}

std::vector<RegionID> Datastructures::all_regions()   // linear
{
    std::vector<RegionID> all_regions;
    if (! regions_.empty()){  // constant
        for (auto& p: regions_){ // Linear
            all_regions.push_back(p.first); // performance of push_back() in a vector is constant
        }

    }
    return all_regions;


}

// constant on average, worst case O(stops_.size + regions_.size)
bool Datastructures::add_stop_to_region(StopID id, RegionID parentid)
{
    auto stop_iter = stops_.find(id); // constant on average, worst case linear in the size of the container.
    auto region_iter = regions_.find(parentid); // constant on averagr, worst case linear in the size of the container.

    // if stop exists, region exists, stop doesn't belong to a region, then return true
    if (stop_iter != stops_.end() && region_iter != regions_.end()
            && stop_iter->second.region_stop_belongs == nullptr){
        Region* region = &(region_iter->second);
        Stop* stop = &(stop_iter->second);
        stop->region_stop_belongs = region;
        region->stops_region_contain.push_back(stop);

        return true;

    } else {
        return false;
    }

}

// constant on average, worst case O(2*regions_.size)
bool Datastructures::add_subregion_to_region(RegionID id, RegionID parentid)
{
    auto child_iter = regions_.find(id); // constant on average, worst case linear in the size of the container.
    auto parent_iter = regions_.find(parentid); // constant on averagr, worst case linear in the size of the container.

    // if two regions exist and id has no parent, the return true
    if (child_iter != regions_.end() && parent_iter != regions_.end()
            && child_iter->second.parent_region == nullptr){
        Region* child = &(child_iter->second);
        Region* parent = &(parent_iter->second);
        child->parent_region = parent;
        parent->sub_regions.push_back(child);

        return true;

    } else {
        return false;
    }

}

std::vector<RegionID> Datastructures::stop_regions(StopID id) // worst: linear
{
    auto stop_iter = stops_.find(id); // constant on average but linear in worst case
    std::vector<RegionID> stop_regions;  // create vector stop_regions
    if (stop_iter != stops_.end() && stop_iter->second.region_stop_belongs != nullptr){
        Stop stop = stop_iter->second;       
        Region* parent_region = stop.region_stop_belongs; // define region that stop with id belongs to
        stop_regions.push_back(parent_region->region_id); // add this direct parent region to return vector

        // if direct region still has parent_region, then add its parent_region to the vector
        while (parent_region->parent_region != nullptr){
            stop_regions.push_back(parent_region->parent_region->region_id);
            parent_region = parent_region->parent_region;
        }


    }
    return stop_regions;
}

void Datastructures::creation_finished()
{
    // Replace this comment with your implementation
    // You don't have to use this method for anything, if you don't need it
}

std::pair<Coord,Coord> Datastructures::region_bounding_box(RegionID id) // O(stop.size)
{
    auto region_iter = regions_.find(id);
    if (region_iter != regions_.end()){

        Region region = region_iter->second;

        // find the stops that a region and its subregions contains
        std::vector<Stop*> stops = region.stops_region_contain;

        stops = region_stops(region, stops);

        std::pair<Coord,Coord> bounding_box = bounding_box_of_stops(stops);
        return bounding_box;
    }

    return {NO_COORD, NO_COORD};
}

std::vector<StopID> Datastructures::stops_closest_to(StopID id) // return 5 closest, O(stops.size)
{
    auto iter = stops_.find(id);
    std::vector<StopID> closest_stops;
    if (iter != stops_.end()){
        Stop stop_with_id = iter->second;
        std::vector<std::pair<StopID, double>> closest_stops_tmp;
        for (auto& p: stops_){       // Linear
            if (p.first != id){
                double distance = euclidean_distance(stop_with_id, p.second);

                // insert new element
                // because we at most have 5 elements in a vector, then the performance is constant
                auto position = std::find_if(closest_stops_tmp.begin(), closest_stops_tmp.end(), [distance](auto s) {
                    return s.second > distance;
                });

                closest_stops_tmp.insert(position, {p.first, distance});

                if (closest_stops_tmp.size() > 5){
                    // delete the last element
                    closest_stops_tmp.pop_back(); // performance of pop_back() in a vector is constant
                }
            }
        }

        // constant, O(5)
        for (std::pair<StopID, double> stop : closest_stops_tmp){
            closest_stops.push_back(stop.first);
        }

    }
    return closest_stops;
}

bool Datastructures::remove_stop(StopID id)  // call not often, performance: linear
{
    // Constant on average, worst case linear in the size of the container.
    auto iter = stops_.find(id);

    if (iter != stops_.end()) {
        // find the parent region that contains this stop
        Region* region = iter->second.region_stop_belongs;

        // first, remove the pointer in the "stops_region_contain" of a Region
        // performance: linear
        for (std::vector<Stop*>::iterator iter = region->stops_region_contain.begin();
             iter != region->stops_region_contain.end(); ++iter){
            if ((*iter)->stopid == id){
                region->stops_region_contain.erase(iter);
                break;
            }
        }

        // Then, remove this stop from stops_(linear)
        for(std::unordered_map<StopID, Stop>::iterator iter = stops_.begin(); iter != stops_.end(); ++iter) {
            if(iter->first == id) {stops_.erase(iter); break;}

        }

        return true;
    }
    return false;
}

RegionID Datastructures::stops_common_region(StopID id1, StopID id2) // linear
{
    // accordind to the function stop_regions()
    // region with id j must be parent of that with id i, if j > i
    std::vector<RegionID> regions1 = stop_regions(id1); // worst: linear
    std::vector<RegionID> regions2 = stop_regions(id2);  // worst: linear

    // Then if regions1 and regions 2 have a common region,
    // for example, regions1[i] == regions2[j]
    // then regions1[i]:regions1.end()== regions[j]:regions2.end()
    // then we can find the common ID according to the reverse
    if (regions1.empty() && regions2.empty()){
        return NO_REGION;
    }else{
        while (!regions1.empty() && !regions2.empty()){
            if (*(regions1.end()-1) == *(regions2.end() - 1) &&
                    ((regions1.size() == 1  || regions2.size() == 1) ||
                    *(regions1.end()-2) != *(regions2.end() - 2)) ){
                return *(regions1.end()-1);
            }else{
                regions1.pop_back();
                regions2.pop_back();
            }
        }
        return NO_REGION;
    }

}

std::pair<Coord, Coord> Datastructures::bounding_box_of_stops(std::vector<Stop*> stops_vector) // performance: O(vector.size)
{
    unsigned int size = stops_vector.size();
    if ( stops_vector.empty()){
        return {NO_COORD,NO_COORD};
    }
    Coord coord_min = stops_vector.at(0)->stop_coord;
    Coord coord_max = stops_vector.at(0)->stop_coord;
    std::pair<Coord, Coord> coord_bounding = {coord_min, coord_max};
    if (size > 1){
        for (unsigned int i = 1; i < size; ++i){
            Coord coord_current = stops_vector.at(i)->stop_coord;
            update_bounding_box(coord_bounding, coord_current);
        }
    }

    return coord_bounding;

}

void Datastructures::update_bounding_box(std::pair<Coord, Coord>& coord_bouding, Coord coord)
{
    Coord& coord_min = coord_bouding.first;
    Coord& coord_max = coord_bouding.second;

    // update x
    if (coord.x < coord_min.x){
        coord_min.x = coord.x;
    } else if(coord.x > coord_max.x){
        coord_max.x = coord.x;
    }

    // update y
    if (coord.y < coord_min.y){
        coord_min.y = coord.y;
    } else if(coord.y > coord_max.y){
        coord_max.y = coord.y;
    }
}

// It traverses a region (a tree with multiple nodes)
std::vector<Stop*> Datastructures::region_stops(Region region, std::vector<Stop*> stops)
{
    for (unsigned int i=0 ; i<region.sub_regions.size(); ++i){
        Region tmp_region = *(region.sub_regions[i]);

        // linear, how many stops are inserted
        stops.reserve(stops.size() + tmp_region.stops_region_contain.size());
        stops.insert(stops.end(), tmp_region.stops_region_contain.begin(), tmp_region.stops_region_contain.end());
        stops = region_stops(tmp_region, stops);

    }

    return stops;
}

double Datastructures::euclidean_distance(Stop stop1, Stop stop2)
{
    int dx = stop1.stop_coord.x - stop2.stop_coord.x;
    int dy = stop1.stop_coord.y - stop2.stop_coord.y;
    double distance = sqrt(dx*dx + dy*dy);
    return distance;
}

