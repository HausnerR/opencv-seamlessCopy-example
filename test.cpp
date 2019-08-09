#include <opencv2/opencv.hpp>


using namespace cv;

int main(int argc, char** argv) {
    // Read images : src image will be cloned into dst
    Mat src = imread("airplane.jpg");
    Mat dst = imread("sky.jpg");


    // Create a rough mask around the airplane.
    /*Mat src_mask = Mat::zeros(src.rows, src.cols, src.depth());

    // Define the mask as a closed polygon
    Point poly[1][7];
    poly[0][0] = Point(8, 160);
    poly[0][1] = Point(60, 108);
    poly[0][2] = Point(302,126);
    poly[0][3] = Point(508,74);
    poly[0][4] = Point(596,180);
    poly[0][5] = Point(544,268);
    poly[0][6] = Point(86,244);

    const Point* polygons[1] = { poly[0] };
    int num_points[] = { 7 };

    // Create mask by filling the polygon

    fillPoly(src_mask, polygons, num_points, 1, Scalar(255,255,255));*/

    // The location of the center of the src in the dst
    Point center(1600,200);

    // Create an all white mask
    Mat src_mask = 255 * Mat::ones(src.rows, src.cols, src.depth());

    // Seamlessly clone src into dst and put the results in output
    Mat output;
    seamlessClone(src, dst, src_mask, center, output, MIXED_CLONE);

    // Save result
    imwrite("opencv-seamless-cloning-example.jpg", output);
}
