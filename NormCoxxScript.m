
NormCoxx = [];

for k=88:100
    k
    for i=1:30181   
        
 %        NormCoxx(i) = dot((ArrgTest(:,j)),ArrgTrain(:,i))/(norm(ArrgTest(:,j))*norm(ArrgTrain(:,i)));
       NormCoxx(i) = dot((ArrgTest(:,k)),ArrgTrain(:,i))/(norm(ArrgTest(:,k))*norm(ArrgTrain(:,i)));
    end


[LargestNorm,Pos] = max(NormCoxx);

% fprintf('Image #: %d',Pos)
% 
n = num2str((Pos));
pl  = [n,'.jpg'];
% imshow(pl)

m = num2str((k));
ml  = [m,'.jpg'];

GS = imread(ml);
G = GS(:,:,1);


% GS = imread('Test1.jpg');
% G = GS(:,:,1);

XR =imread(pl);

%Using HSV
C = rgb2hsv (XR);
H = C(:,:,1);
S = C(:,:,2);
V = im2double(GS(:,:,1));

FINAL (:,:,1) = H;
FINAL (:,:,2) = S;
FINAL (:,:,3) = V;

% C = makecform('srgb2lab');
% I_xyz = applycform(XR,C);
% L = I_xyz(:,:,1);
% A = I_xyz(:,:,2);
% B = I_xyz(:,:,3);



% H = I_xyz(:,:,1);
% S = I_xyz(:,:,2);
% V = im2double(I_xyz(:,:,3));



% FINAL (:,:,1) = G;
% FINAL (:,:,2) = A;
% FINAL (:,:,3) = B;

 y = num2str((k));
 yk  = [y,'FINAL','.jpg'];
 %imshow(hsv2rgb(FINAL))
imwrite(hsv2rgb(FINAL),yk,'jpg');
end