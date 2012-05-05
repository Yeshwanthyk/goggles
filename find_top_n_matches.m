function [best_images]=find_top_n_matches(n)
NormCoxx = [];
load gist_entire.mat 
load Arrg_dest.mat
for k=1:n
   for i=1:6609
       normal_corrl(i) = dot((Arrg_dest(:,1)),Arrg(:,i))/(norm(Arrg_dest(:,1))*norm(Arrg(:,i)));
   end
    

%Find the best matching image for the source image.... 
[bestnormcorr,best_img_pos] = max(normal_corrl);

%remove the entry from Arrg...
Arrg(:,best_img_pos) = 0;


best_images(k) = best_img_pos;

%fprintf('%d \n',best_img_pos);

end