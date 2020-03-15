with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "default";
    
    buildInputs = [
        binutils
        gcc
    ];
    LD_LIBRARY_PATH="${xorg.libX11}/lib:${xorg.libXcursor}/lib:${xorg.libXrandr}/lib:${xorg.libXi}/lib:${libglvnd}/lib:/run/opengl-driver/lib";
}