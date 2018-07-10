/*
* @Author: ghma
* @Date:   2018-07-09 14:44:11
* @Last Modified by:   ghma
* @Last Modified time: 2018-07-09 16:31:30
*/
#include <stdio.h>
#include <math.h>
#include "./include/darknet.h"

int process_single_im(char * filename, REQS * req)
{
    int init_flag, i, j;
    init_flag = init("cfg/coco.data", "./cfg/yolov3.cfg", "yolov3.weights", req);
    if (init_flag) f_detector(req, filename);
    return 1;
}

int main(int argc, char ** argv)
{
    REQS req={0};
    req.thresh = .95;
    req.nms = .5;
    if (argc < 4) {
        fprintf(stderr, " >> usage:\n >> ./facedetector [single/directory] [image_file_path/image_folder_path] threshold \n");
        return 0;
    }
    if (argv[3]) req.thresh = atof(argv[3]);
    if (! strcmp(argv[1], "single")) {
        if (argv[2]) process_single_im(argv[2], &req);
    }
    return 0;
}
