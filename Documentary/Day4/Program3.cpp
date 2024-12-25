CODE:-
  
#include <iostream>
#include <vector>
#include <algorithm>

struct Video {
    std::string title;
    int totalViews;
    double userRating;
    int releaseYear;

    // Constructor
    Video(std::string title, int views, double rating, int year)
        : title(title), totalViews(views), userRating(rating), releaseYear(year) {}
};

bool compareVideos(const Video &a, const Video &b) {
    if (a.totalViews != b.totalViews) {
        return a.totalViews > b.totalViews; // Sort by views
    }
    return a.releaseYear > b.releaseYear; // Then by recency
}

int main() {
    std::vector<Video> videos = {
        Video("Movie A", 1000, 4.5, 2021),
        Video("Movie B", 1500, 4.7, 2022),
        Video("Movie C", 1000, 4.8, 2023)
    };

    std::sort(videos.begin(), videos.end(), compareVideos);

    for (const auto &v : videos) {
        std::cout << "Video Title: " << v.title << ", Views: " << v.totalViews << std::endl;
    }

    return 0;
}
/*
OUTPUT:-

Video Title: Movie B, Views: 1500
Video Title: Movie C, Views: 1000
Video Title: Movie A, Views: 1000
*/
