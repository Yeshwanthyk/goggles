
function imagelast(pl)

[Arrg_dest] = computegist(pl);

[img_ind] = find_top_n_matches(10);

fid = fopen('input.txt', 'w');
fprintf(fid, '%d ', img_ind); 
fclose(fid);

unix('~/Desktop/CpFinal/getTags 10 10    < input.txt > finaltags.txt');

system ('python ~/Desktop/CpFinal/gist_creator.py everything.txt')