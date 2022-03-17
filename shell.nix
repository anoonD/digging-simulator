# save this as shell.nix
{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
  nativeBuildInputs = [ pkgs.cmake ];
  buildInputs = [ pkgs.sqlite pkgs.fmt_8 ];
}
