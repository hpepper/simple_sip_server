# These are the packages required for development (on ubuntu)
# sudo puppet apply dev_requirements.pp
package { 'libboost-program-options-dev': ensure => present }
