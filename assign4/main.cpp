/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  Forecast forecast;
  auto begin = dailyWeather.begin();
  auto end = dailyWeather.end();
  auto min_temp = std::min_element(begin, end);
  auto max_temp = std::max_element(begin, end);
  auto avg_temp = std::accumulate(begin, end, 0.0) / dailyWeather.size();
  forecast.min_temp = *min_temp;
  forecast.max_temp = *max_temp;
  forecast.avg_temp = avg_temp;
  return forecast;
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  std::vector<Forecast> forecasts;
  std::transform(weatherData.begin(), weatherData.end(), std::back_inserter(forecasts), compute_forecast);
  return forecasts;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  auto filtered_data = forecastData;
  auto filter = [kMaxTempRequirement, uAvgTempRequirement](const Forecast& forecast) {
    return (forecast.max_temp - forecast.min_temp) <= kMaxTempRequirement || forecast.avg_temp < uAvgTempRequirement;
  };
  filtered_data.erase(std::remove_if(filtered_data.begin(), filtered_data.end(), filter), filtered_data.end());
  return filtered_data;
}


std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  std::vector<Forecast> shuffled_data = forecastData;
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(shuffled_data.begin(), shuffled_data.end(), g);
  return shuffled_data;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  std::vector<Forecast> forecasts = get_forecasts(weatherData);
  std::vector<Forecast> filtered_data = get_filtered_data(forecasts);
  std::vector<Forecast> shuffled_data = get_shuffled_data(filtered_data);
  return shuffled_data;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"