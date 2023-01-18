{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
          config = {
            allowUnfree = false;
            permittedInsecurePackages = [ "python-2.7.18.6" ];
          };
        };
        pyyaml = pkgs.python2Packages.buildPythonPackage rec {
          pname = "PyYAML";
          version = "3.12";
          src = pkgs.python2Packages.fetchPypi {
            inherit pname version;
            sha256 = "sha256-WSdmxjAyB6IO/ERVh3eDItf3OxYb2ZTyJ62qNBuiEqs=";
          };
        };
        plastex = pkgs.python2Packages.buildPythonPackage rec {
          pname = "plasTeX";
          version = "1.0";
          src = pkgs.fetchFromGitHub {
            owner = "plastex";
            repo = "plastex";
            rev = "1.0.0";
            sha256 = "sha256-82aMQ2915PWT82BL8u3kRf2rbakqsoOtyOMyO5UQY6w=";
          };
        };
        six = pkgs.python2Packages.buildPythonPackage rec {
          pname = "six";
          version = "1.16.0";
          src = pkgs.python2Packages.fetchPypi {
            inherit pname version;
            sha256 = "sha256-HmHDdHehYmRY4297HYKqXJsJT6SAKJIHLknenGDEySY=";
          };
          doCheck = false;
        };
        problemtools = pkgs.python2Packages.buildPythonPackage {
          name = "problemtools";
          src = pkgs.fetchgit {
            url = "https://github.com/Kattis/problemtools.git";
            rev = "v1.20191126";
            sha256 = "sha256-gkBfV7DgSHmh9Xf9Avl0mqPFeyQxu+nvuCR2W1jP3SM=";
            fetchSubmodules = true;
            leaveDotGit = true;
          };
          doCheck = false;
          propagatedBuildInputs = let p = pkgs;
          in [ p.gmpxx p.boost pyyaml plastex six ];
          nativeBuildInputs = let p = pkgs; in [ p.git p.automake p.autoconf ];
        };
      in {
        devShell = pkgs.mkShell {
          nativeBuildInputs = [ pkgs.bashInteractive problemtools ];
        };
      });
}
