#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define pb push_back
#define FLOAT_MAX 3.40282e+038
#define FLOAT_MIN 1.17549e-038

struct alternative{
    std::vector<float> best;
    std::vector<float> worst;
};

struct distance{
    std::vector<float> best;
    std::vector<float> worst;
};


std::vector<std::vector<float>> normalize(std::vector<std::vector<float>> evaluation_matrix){

    std::vector<float> denoms;

    for(auto row : evaluation_matrix){
        float temp_denom = 0;
        for(auto record : row){
            temp_denom += (record * record);
        }
        denoms.pb(sqrt(temp_denom));
    }

    for(int i = 0; i < evaluation_matrix.size(); i++){
        for(int j = 0; j < evaluation_matrix[i].size(); j++){
            evaluation_matrix[i][j] /= denoms[i];
        }
    }

    return evaluation_matrix;
}

std::vector<std::vector<float>> weigthed_normalized(std::vector<std::vector<float>> normalized_evaluation_matrix, std::vector<float> weight){
    for(int i = 0; i < normalized_evaluation_matrix.size(); i++){
        for(int j = 0; j < normalized_evaluation_matrix[i].size(); j++){
            normalized_evaluation_matrix[i][j] *= weight[i];
        }
    }

    return normalized_evaluation_matrix;
}

alternative alternatives(std::vector<std::vector<float>> weigthed_normalized){
    alternative alt;
    size_t row = weigthed_normalized.size(), col = weigthed_normalized[0].size();

    for(int i = 0; i < col; i++){
        float _min = FLOAT_MAX, _max = FLOAT_MIN;
        for(int j = 0; j < row; j++){
            _max = std::max(weigthed_normalized[j][i], _max);
            _min = std::min(weigthed_normalized[j][i], _min);
        }
        alt.best.pb(_max);
        alt.worst.pb(_min);
    }

    return alt;
}

distance distances(std::vector<std::vector<float>> weigthed_normalized, std::vector<float> best_alternative, std::vector<float> worst_alternative){
    distance dist;
    for(int i = 0; i < weigthed_normalized.size(); i++){
        float temp_best_distance = 0;
        float temp_worst_distance = 0;
        for(int j = 0; j < weigthed_normalized[i].size(); j++){
            temp_best_distance += pow((weigthed_normalized[i][j] - best_alternative[j]), 2);
            temp_worst_distance += pow((weigthed_normalized[i][j] - worst_alternative[j]), 2);
        }
        dist.best.pb(temp_best_distance);
        dist.worst.pb(temp_worst_distance);
    }
    return dist;
}

std::vector<float> rank_by_worst_distance(std::vector<float> best_distance, std::vector<float> worst_distance){
    std::vector<float> res;
    for(int i = 0; i < best_distance.size(); i++){
        float temp_res = worst_distance[i] / (worst_distance[i] + best_distance[i]);
        res.pb(temp_res);
    }
    return res;
}



int main(){

    std::vector<std::vector<float>> input = {
        {1, 1, 0, 0.75, 1, 0, 0.5, 0.75, 0.5, 1, 1, 0, 0, 0.5},
        {0.75, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1},
        {0, 0.5, 1, 0, 0, 0, 0, 1, 0.5, 0, 0, 0, 0.5, 0.5},
        {1, 1, 1, 0.75, 1, 0.75, 0.5, 1, 0.5, 0.5, 1, 1, 0.5, 1},
        {0.75, 0.5, 0.5, 0.75, 0, 0.75, 0.75, 1, 0.5, 0.5, 0, 0.5, 0.5, 0.5}
    };

    std::vector<float> weight = {
        0.75, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 0.75, 1, 0.75
    };

    std::vector<std::vector<float>> res = normalize(input);
    std::vector<std::vector<float>> weigthed_norm = weigthed_normalized(res, weight);
    alternative alt = alternatives(weigthed_norm);
    distance dist = distances(weigthed_norm, alt.best, alt.worst);
    std::vector<float> rank = rank_by_worst_distance(dist.best, dist.worst);


    std::cout<<"Rank vector\n";
    for(int i = 0; i < rank.size(); i++){
        std::cout<<"Criterion "<<(i+1)<<"\t"<<rank[i]<<"\n";
    }

}