// link 2
// base cylinder
hb = 0.07;
rb= 0.015;
translate(v=[0, 0, -hb/2]){
 rotate(a=[0, 0, 0]){
  cylinder($fn=60, h=hb, r1=rb, r2=rb, center=false);
 }
}

// arm cylinder
ha = 0.20;
ra= 0.015;
translate(v=[0, 0, 0]){
 rotate(a=[-90, 0, -90]){
  cylinder($fn=60, h=ha, r1=ra, r2=ra, center=false);
 }
}