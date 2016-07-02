

#include "cv.h"
#include "highgui.h"

int  VideoToImage(char* videoName,char* outDir,char* imgExt,int maxFrameCount)
 {
   CvCapture *cap= cvCaptureFromFile(videoName);
   if (cap==NULL)
   {
    return 0;
  }
     //保存图片的文件夹路径一定要有，因为OpenCV不会自动创建文件夹
   /*if (_access(outDir,0)==-1)
   {
     recursive_mkdir(outDir);
      std::cout<<"the ouput directory does not exist, and the have been created autonomously!"<<std::endl;
   }*/
  char cur_fn[255];//保存当前帧所得图片的文件名
  IplImage* pImg=NULL;
 int frame=0;
  while((pImg=cvQueryFrame(cap))!=NULL/*&&(frame<maxFrameCount)*/)
  {               
   strcpy_s(cur_fn,"");
   sprintf_s(cur_fn,"%s%d%s",outDir,frame,imgExt);//这里的设置适合形如 123.jpg 124.jpg的图片序列
   cvSaveImage(cur_fn,pImg,NULL);
   frame++;
  }
  cvReleaseImage(&pImg);
  cvReleaseCapture(&cap);
	return frame;
 }

	


int main(int argc, char* argv[])
{
	
	char videoName[100]="F:\\二维图片路径\\20160604-170820.avi";
	char outDir[100]="f:\\gei\\";
	char imgExt[100]=".png";
	int maxFrameCount=1000;
	int FrameCount=VideoToImage(videoName,outDir,imgExt,maxFrameCount);
	printf("FrameCount=%d\n",FrameCount);
	//while(1);
	return 0;
}