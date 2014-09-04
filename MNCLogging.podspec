Pod::Spec.new do |s|
  s.name         = 'MNCLogging'
  s.version      = '1.0.0'
  s.summary      = 'Simple Objective-C logging'
  s.author = {
    'Matthias Tretter' => 'm.yellow@gmx.at'
  }
  s.source = {
    :git => 'https://github.com/myell0w/MNCLogging.git',
    :tag => '1.0.0'
  }
  s.source_files = '*.{h,m}'
end