/*
* @Author: ghma
* @Date:   2018-07-09 14:44:11
* @Last Modified by:   ghma
* @Last Modified time: 2018-07-15 11:33:41
*/
#include <stdio.h>
#include <math.h>
#include "./include/darknet.h"

int process_single_im(char * filename, REQS * req)
{
    int init_flag, i, j;
    init_flag = init("cfg/coco.data", "./cfg/yolov3.cfg", "backup/yolov3_ft_570000.weights", req);
    if (init_flag) f_detector(req, filename);
    return 1;
}

int main(int argc, char ** argv)
{
    REQS req     = {0};
    req.thresh   = .95;
    req.nms      = .5;
    req.scale[0] = 0;
    if (argc == 3) {
        req.thresh = .4;
        req.scale[1] = .2;
        fprintf(stderr, " >> use deafault values instead\n");
    } else if (argc == 4) {
        if (argv[3]) req.thresh = atof(argv[3]);
    } else if (argc == 5){
        if (argv[3]) req.thresh = atof(argv[3]);
        if (argv[4]) req.scale[0] = atof(argv[4]);
    } else {
        fprintf(stderr, " >> usage:\n >> ./facedetector [single/directory] [image_file_path/image_folder_path] threshold1  scale_flag\n");
        return 0;
    }
    if (! strcmp(argv[1], "single")) {
        if (argv[2]) process_single_im(argv[2], &req);
    }
    return 0;
}
