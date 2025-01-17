
Arrg = [];
% for i=1:6609   
%     n = num2str(i);
%     pl  = [n,'.jpg'];

img = imread('test.jpg');
imgr = imresize(img,[86,86]);

% Parameters:
Nblocks = 4;
imageSize = 86; 
orientationsPerScale = [8 8 4];
numberBlocks = 4;

% Precompute filter transfert functions (only need to do this one, unless image size is changes):
createGabor(orientationsPerScale, imageSize); % this shows the filters
G = createGabor(orientationsPerScale, imageSize);

% Computing gist requires 1) prefilter image, 2) filter image and collect
% output energies
output = prefilt(double(imgr), 4);
g = gistGabor(output, numberBlocks, G);
Arrg = cat(2,Arrg,g);
% fprintf('The GIFT has been completed till %d \n',i);

% end

%save gistentire.mat Arrg
