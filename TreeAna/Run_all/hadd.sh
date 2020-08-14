current_date=`date +"%Y_%m_%d"`

Dir_name="$current_date$index"

echo $Dir_name

mkdir -p ~/temp/$Dir_name

hadd -k  /u/xbai/temp/$Dir_name/splineQA.root output/data/2018/LHC18?/*/pass3/*/hist.root
